using LmkImageLib;
using LmkImageLib.Wpf;
using LmkPhotoViewer.Model.Controls;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LmkPhotoViewer.View.Controls
{
    /// <summary>
    /// Follow steps 1a or 1b and then 2 to use this custom control in a XAML file.
    ///
    /// Step 1a) Using this custom control in a XAML file that exists in the current project.
    /// Add this XmlNamespace attribute to the root element of the markup file where it is 
    /// to be used:
    ///
    ///     xmlns:MyNamespace="clr-namespace:LmkPhotoViewer.View.Controls"
    ///
    ///
    /// Step 1b) Using this custom control in a XAML file that exists in a different project.
    /// Add this XmlNamespace attribute to the root element of the markup file where it is 
    /// to be used:
    ///
    ///     xmlns:MyNamespace="clr-namespace:LmkPhotoViewer.View.Controls;assembly=LmkPhotoViewer.View.Controls"
    ///
    /// You will also need to add a project reference from the project where the XAML file lives
    /// to this project and Rebuild to avoid compilation errors:
    ///
    ///     Right click on the target project in the Solution Explorer and
    ///     "Add Reference"->"Projects"->[Browse to and select this project]
    ///
    ///
    /// Step 2)
    /// Go ahead and use your control in the XAML file.
    ///
    ///     <MyNamespace:MovableImage/>
    ///
    /// </summary>
    public class MovableImage : Canvas, IMovableImageMatrix
    {
        static MovableImage()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof(MovableImage), new FrameworkPropertyMetadata(typeof(MovableImage)));
        }

        public MovableImage()
        {
            this.imageControl = new Image();
            this.imageControl.RenderTransform = new MatrixTransform();
            RenderOptions.SetBitmapScalingMode(this.imageControl, BitmapScalingMode.NearestNeighbor);

            this.Children.Add(this.imageControl);
        }

        private Image imageControl;

        #region override method

        protected override void OnMouseWheel(MouseWheelEventArgs e)
        {
            var position = e.GetPosition(this);
            if (e.Delta > 0)
                this.Scale(position.X, position.Y, MovableImageZoomType.ZoomUp);
            else 
                this.Scale(position.X, position.Y, MovableImageZoomType.ZoomDown);

            base.OnMouseWheel(e);
        }

        private bool isDragging = false;
        private Matrix startMatrix = Matrix.Identity;
        private Point startPoint;

        protected override void OnMouseDown(MouseButtonEventArgs e)
        {
            if (e.LeftButton == MouseButtonState.Pressed)
            {
                this.startMatrix = this.Matrix;
                this.startPoint = e.GetPosition(this);

                CaptureMouse();
            }

            base.OnMouseDown(e);
        }

        protected override void OnMouseUp(MouseButtonEventArgs e)
        {
            if(e.LeftButton == MouseButtonState.Released)
            {
                ReleaseMouseCapture();
            }
            base.OnMouseUp(e);
        }

        protected override void OnMouseMove(MouseEventArgs e)
        {
            if(e.LeftButton == MouseButtonState.Pressed)
            {
                var matrix = this.startMatrix;
                var point = e.GetPosition(this);
                matrix.Translate(point.X - this.startPoint.X, point.Y - this.startPoint.Y);
                this.Matrix = matrix;
            }

            base.OnMouseMove(e);
        }

        protected override void OnRenderSizeChanged(SizeChangedInfo sizeInfo)
        {
            FitImage(this.ActualWidth, this.ActualHeight);

            base.OnRenderSizeChanged(sizeInfo);
        }

        #endregion

        #region Dependency Property

        /// <summary>
        /// Image transformation matrix
        /// </summary>
        public static readonly DependencyProperty SourceProperty =
            DependencyProperty.Register("Source",
            typeof(LmkImage),
            typeof(MovableImage),
            new PropertyMetadata(null, new PropertyChangedCallback(OnSourcePropertyChanged)));

        private static void OnSourcePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            var control = d as MovableImage;
            if (control.imageControl == null)
                return;

            var image = e.NewValue as LmkImage;
            if (image == null)
            {
                control.imageControl.Source = null;
                return;
            }

            control.imageControl.Source = image.ToWriteableBitmap();
            control.FitImage();
        }

        /// <summary>
        /// Image transformation matrix
        /// </summary>
        public LmkImage Source
        {
            get { return (LmkImage)GetValue(SourceProperty); }
            set
            {
                SetValue(SourceProperty, (LmkImage)value);
            }
        }

        /// <summary>
        /// Image transformation matrix
        /// </summary>
        public static readonly DependencyProperty MatrixProperty =
            DependencyProperty.Register("Matrix",
            typeof(System.Windows.Media.Matrix),
            typeof(MovableImage),
            new PropertyMetadata(Matrix.Identity, new PropertyChangedCallback(OnMatrixPropertyChanged)));

        private static void OnMatrixPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            MovableImage control = d as MovableImage;
            control.SetMatrix((Matrix)e.NewValue);
        }

        /// <summary>
        /// Image transformation matrix
        /// </summary>
        public System.Windows.Media.Matrix Matrix
        {
            get { return (System.Windows.Media.Matrix)GetValue(MatrixProperty); }
            set
            {
                SetValue(MatrixProperty, (System.Windows.Media.Matrix)value);
            }
        }

        /// <summary>
        /// Image zoom rate step
        /// </summary>
        public static readonly DependencyProperty ZoomStepProperty =
            DependencyProperty.Register("ZoomStep",
            typeof(double),
            typeof(MovableImage),
            new PropertyMetadata(0.2));

        /// <summary>
        /// Image zoom rate step
        /// </summary>
        public double ZoomStep
        {
            get { return (double)GetValue(ZoomStepProperty); }
            set
            {
                SetValue(ZoomStepProperty, (double)value);
            }
        }

        #endregion Dependency Property

        #region Property

        #endregion

        #region Public Methods

        /// <summary>
        /// Fit to visible window size
        /// </summary>
        public void FitImage()
        {
            FitImage(this.ActualWidth, this.ActualHeight);
        }

        /// <summary>
        /// Fit to given size
        /// </summary>
        /// <param name="width">fit width</param>
        /// <param name="height">fit height</param>
        public void FitImage(double width, double height)
        {
            var size = GetImageSize();
            double unifiedRate = Math.Min(width / size.Width, height / size.Height);
            if (double.IsInfinity(unifiedRate) || double.IsNaN(unifiedRate))
                return;

            var matrix = Matrix.Identity;
            matrix.Scale(unifiedRate, unifiedRate);
            matrix.Translate(Math.Abs(unifiedRate * size.Width - width) / 2.0, Math.Abs(unifiedRate * size.Height - height) / 2.0); // align center
            this.Matrix = matrix;
        }

        #endregion

        #region Private Methods

        private void SetMatrix(Matrix mat)
        {
            var matrixTransform = this.imageControl.RenderTransform as MatrixTransform;
            matrixTransform.Matrix = mat;
        }

        /// <summary>
        /// Get image size
        /// </summary>
        /// <returns>size</returns>
        private Size GetImageSize()
        {
            if (this.Source == null)
                return new Size();

            return new Size(this.Source.Width, this.Source.Height);
        }

        #endregion 
    }
}
