using LmkImageLib;
using LmkImageLib.Wpf;
using LmkPhotoViewer.Messages;
using LmkPhotoViewer.Model;
using LmkPhotoViewer.Model.Controls;
using LmkPhotoViewer.View.Controls;
using Microsoft.Toolkit.Mvvm.ComponentModel;
using Microsoft.Toolkit.Mvvm.Input;
using Microsoft.Toolkit.Mvvm.Messaging;
using Microsoft.Toolkit.Mvvm.Messaging.Messages;
using System;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;

namespace LmkPhotoViewer.ViewModel
{
    public class AboutViewModel : ObservableRecipient
    {
        /// <summary>
        /// Initializes a new instance of the AboutViewModel class.
        /// </summary>
        public AboutViewModel()
        {
        }

        #region Property

        /// <summary>
        /// Contributor
        /// </summary>
        public string Contributor
        {
            get
            {
                return ApplicationInformation.Contributor;
            }
        }

        /// <summary>
        /// Reference
        /// </summary>
        public string Reference
        {
            get
            {
                return ApplicationInformation.Reference;
            }
        }

        #endregion

        #region Command

        private ICommand closeCommand;

        public ICommand CloseCommand
        {
            get
            {
                return closeCommand ?? (closeCommand = new RelayCommand(() =>
                {
                    // Close this window.
                    WeakReferenceMessenger.Default.Send(new ActionMessage("Close"));
                }));
            }
        }
        #endregion

    }
}