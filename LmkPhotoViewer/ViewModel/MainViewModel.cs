using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using LmkPhotoViewer.Model;
using LmkPhotoViewer.Model.Controls;
using System.Threading.Tasks;
using System.Windows;

namespace LmkPhotoViewer.ViewModel
{
    /// <summary>
    /// This class contains properties that the main View can data bind to.
    /// <para>
    /// Use the <strong>mvvminpc</strong> snippet to add bindable properties to this ViewModel.
    /// </para>
    /// <para>
    /// You can also use Blend to data bind with the tool's support.
    /// </para>
    /// <para>
    /// See http://www.galasoft.ch/mvvm
    /// </para>
    /// </summary>
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

        private RelayCommand pressF1KeyCommand;
        public RelayCommand PressF1KeyCommand
        {
            get
            {
                return pressF1KeyCommand ?? (pressF1KeyCommand = new RelayCommand(() =>
                {
                    // Show about window.
                    Messenger.Default.Send(new NotificationMessage("ShowAbout"));
                }));
            }
        }

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