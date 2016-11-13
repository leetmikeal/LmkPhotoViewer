using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace LmkPhotoViewer
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        /// <summary>
        /// Constructor
        /// </summary>
        public App()
        {
            // Gathering all exceptions
            this.DispatcherUnhandledException += this.Application_DispatcherUnhandledException;
            AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;

            // if main window closed, the application close too.
            this.ShutdownMode = ShutdownMode.OnMainWindowClose;
        }

        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);
        }

        #region Gahering all exceptions

        /// <summary>
        /// unhandled all exceptions is catched.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            Exception ex = e.ExceptionObject as Exception;
            MessageBox.Show(ex.Message, "Exception",
                MessageBoxButton.OK, MessageBoxImage.Error);
            this.Shutdown();
        }

        /// <summary>
        /// A event since unhandled was raised.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Application_DispatcherUnhandledException(object sender, System.Windows.Threading.DispatcherUnhandledExceptionEventArgs e)
        {
            this.DispatcherExeption(sender, e);
        }

        /// <summary>
        /// Handling exception errors.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        internal void DispatcherExeption(object sender, System.Windows.Threading.DispatcherUnhandledExceptionEventArgs e)
        {
            if(e.Exception is OverflowException && e.Exception.Source == "PresentationFramework")
            {

            }
            else
            {
                // Showing window
                //ErrorWindow errorWindow = new ErrorWindow(e.Exception);
                //errorWindow.ShowDialog();
            }

            e.Handled = true;
        }

        #endregion Gahering all exceptions
    }
}
