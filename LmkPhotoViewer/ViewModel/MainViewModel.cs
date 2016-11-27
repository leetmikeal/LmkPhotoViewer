using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.CommandWpf;
using LmkImageLib;
using LmkImageLib.Wpf;
using LmkPhotoViewer.Model;
using LmkPhotoViewer.Model.Controls;
using LmkPhotoViewer.View.Controls;
using System;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;

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

            // Raise thread
            AsyncStartCheckFileThread();
        }

        #region Method

        private async void AsyncStartCheckFileThread()
        {
            for(;;)
            {
                try
                {
                    await Task.Run(() => StartCheckFileThread());
                }
                catch
                {
                    // ignore error
                }
            }
        }

        private void StartCheckFileThread()
        {
            for(;;)
            {
                if(this.Image  != null && this.Image.FileInfo != null)
                {
                    bool? updated = this.Image.FileInfo.CheckUpdated();
                    if (updated == true) // updated
                        this.Image.Refresh();
                    else if (updated == null) // removed
                        this.Image = null;
                }
                System.Threading.Thread.Sleep(1000);
            }
        }

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