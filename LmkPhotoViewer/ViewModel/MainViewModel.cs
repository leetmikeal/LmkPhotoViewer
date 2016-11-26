using System;
using System.Linq;
using GalaSoft.MvvmLight;
using LmkImageLib;
using LmkImageLib.Wpf;

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
                RaisePropertyChanged(() => ImageSource);
            }
        }

        /// <summary>
        /// Displaying image convert from source image
        /// </summary>
        public System.Windows.Media.ImageSource ImageSource
        {
            get
            {
                if (Image == null)
                    return null;
                return Image.ToWriteableBitmap();
            }
        }

        #endregion
    }
}