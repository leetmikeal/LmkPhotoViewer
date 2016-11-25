using System;
using System.Collections.Generic;
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

namespace LmkPhotoViewer.View
{
    /// <summary>
    /// Follow steps 1a or 1b and then 2 to use this custom control in a XAML file.
    ///
    /// Step 1a) Using this custom control in a XAML file that exists in the current project.
    /// Add this XmlNamespace attribute to the root element of the markup file where it is 
    /// to be used:
    ///
    ///     xmlns:MyNamespace="clr-namespace:LmkPhotoViewer.View.Control"
    ///
    ///
    /// Step 1b) Using this custom control in a XAML file that exists in a different project.
    /// Add this XmlNamespace attribute to the root element of the markup file where it is 
    /// to be used:
    ///
    ///     xmlns:MyNamespace="clr-namespace:LmkPhotoViewer.View.Control;assembly=LmkPhotoViewer.View.Control"
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
    public class MovableImage : Image
    {
        static MovableImage()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof(MovableImage), new FrameworkPropertyMetadata(typeof(MovableImage)));
        }

        public MovableImage()
        {
            this.RenderTransform = new MatrixTransform();
        }

        protected override void OnPropertyChanged(DependencyPropertyChangedEventArgs e)
        {
            if (e.Property == Image.SourceProperty)
                FitImage(100, 100);

            base.OnPropertyChanged(e);
        }


        #region Dependency Property

        ///// <summary>
        ///// Image transformation matrix
        ///// </summary>
        //public static readonly DependencyProperty MatrixProperty =
        //    DependencyProperty.Register("Matrix",
        //    typeof(System.Windows.Media.Matrix),
        //    typeof(MovableImage),
        //    new PropertyMetadata(Matrix.Identity));

        ///// <summary>
        ///// Image transformation matrix
        ///// </summary>
        //public System.Windows.Media.Matrix Matrix
        //{
        //    get { return (System.Windows.Media.Matrix)GetValue(MatrixProperty); }
        //    set 
        //    {
        //        SetValue(MatrixProperty, (System.Windows.Media.Matrix)value);
        //    }
        //}

        #endregion Dependency Property

        #region Methods

        public void FitImage(int width, int height)
        {
            var size = GetImageSize();
            double unifiedRate = Math.Min(width / size.Width, height / size.Height);

            var matrix = Matrix.Identity;
            matrix.Scale(unifiedRate, unifiedRate);
            SetMatrix(matrix);
        }

        private void SetMatrix(Matrix mat)
        {
            var transform = this.RenderTransform as MatrixTransform;
            if (transform == null)
                return;

            transform.Matrix = mat;
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

        #endregion Methods
    }
}
