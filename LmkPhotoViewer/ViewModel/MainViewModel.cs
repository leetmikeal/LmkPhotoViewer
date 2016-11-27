using System;
using System.Linq;
using GalaSoft.MvvmLight;
using LmkImageLib;
using LmkImageLib.Wpf;
using GalaSoft.MvvmLight.CommandWpf;
using System.Windows.Input;
using LmkPhotoViewer.View.Controls;
using System.Windows.Media;
using LmkPhotoViewer.Model.Controls;

namespace LmkPhotoViewer.ViewModel
{
    public class MainViewModel : ViewModelBase
    {
        /// <summary>
        /// Initializes a new instance of the MainViewModel class.
        /// </summary>
        public MainViewModel()
        {
            ////if (IsInDesignMode)
            ////{
            ////    // Code runs in Blend --> create design time data.
            ////}
            ////else
            ////{
            ////    // Code runs "for real"
            ////}

            // load initial image
            if(System.IO.File.Exists(AppConfig.Instance.Start.FilePath))
            {
                this.Image = new LmkImage(AppConfig.Instance.Start.FilePath);
            }
        }

        #region Method

        /// <summary>
        /// Load from file path
        /// </summary>
        /// <param name="v"></param>
        internal void SetImage(string v)
        {
            this.Image = new LmkImage(v);
        }

        #endregion

        #region Property

        private string windowTitle = "LmkPhotoViewer";

        /// <summary>
        /// Window title
        /// </summary>
        public string WindowTitle
        {
            get
            {
                return windowTitle;
            }
            set
            {
                windowTitle = value;
                RaisePropertyChanged(() => WindowTitle);
            }
        }

        private LmkImage image;

        /// <summary>
        /// Source image
        /// </summary>
        public LmkImage Image
        {
            get
            {
                return image;
            }
            set
            {
                image = value;
                RaisePropertyChanged(() => Image);
            }
        }

        private MovableImageState imageViewState;

        /// <summary>
        /// Image view state
        /// </summary>
        public MovableImageState ImageViewState
        {
            get
            {
                return imageViewState;
            }
            set
            {
                imageViewState = value;
                RaisePropertyChanged(() => ImageViewState);
            }
        }

        #endregion

        #region Command

        //private RelayCommand<MouseWheelEventArgs> mouseWheelCommand;
        //public RelayCommand<MouseWheelEventArgs> MouseWheelCommand
        //{
        //    get
        //    {
        //        return mouseWheelCommand ?? (mouseWheelCommand = new RelayCommand<MouseWheelEventArgs>((e) =>
        //        {
        //            if (e.Delta > 0)
        //                this.Scale(e.GetPosition);
        //        }));
        //    }
        //}

        #endregion
    }
}