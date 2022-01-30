using LmkPhotoViewer.Messages;
using LmkPhotoViewer.ViewModel;
using Microsoft.Toolkit.Mvvm.Messaging;
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

namespace LmkPhotoViewer
{
    /// <summary>
    /// Interaction logic for AboutWindow.xaml
    /// </summary>
    public partial class AboutWindow : Window
    {
        public AboutWindow()
        {
            InitializeComponent();

            this.DataContext = App.Current.Services.GetService(typeof(AboutViewModel));

            WeakReferenceMessenger.Default.Register<ActionMessage>(this, NotificationMessageReceived);
        }

        private void NotificationMessageReceived(object recipient, ActionMessage msg)
        {
            if (msg.Response == "Close")
            {
                this.Close();
            }
        }


    }
}
