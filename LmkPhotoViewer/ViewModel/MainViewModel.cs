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
using System.Windows;

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
                this.Image = new DisplayImage(AppConfig.Instance.Start.FilePath);
            }
        }

        #region Method

        #endregion

        #region Property

        /// <summary>
        /// Window title
        /// </summary>
        public string WindowTitle
        {
            get
            {
                if (this.Image == null)
                    return "LmkPhotoViewer";
                else
                {
                    return this.Image.FilePath;
                }

                return "";
            }
        }

        private DisplayImage image;

        /// <summary>
        /// Source image
        /// </summary>
        public DisplayImage Image
        {
            get
            {
                return image;
            }
            set
            {
                image = value;
                RaisePropertyChanged(() => Image);
                RaisePropertyChanged(() => WindowTitle);
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

        private RelayCommand<DragEventArgs> dropCommand;
        public RelayCommand<DragEventArgs> DropCommand
        {
            get
            {
                return dropCommand ?? (dropCommand = new RelayCommand<DragEventArgs>((e) =>
                {
                    string[] files = e.Data.GetData(DataFormats.FileDrop) as string[];
                    if (files != null && files.Length > 0)
                    {
                        this.Image = new DisplayImage(files[0]);
                    }
                }));
            }
        }

        #endregion
    }
}