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

        private LmkImage image;

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

        public System.Windows.Media.ImageSource ImageSource
        {
            get
            {
                if (Image == null)
                    return null;
                return Image.ToWriteableBitmap();
            }
        }
    }
}