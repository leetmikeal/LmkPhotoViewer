﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using GalaSoft.MvvmLight;

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
            this.Resources["Locator"] = new ViewModel.ViewModelLocator();

            try
            {
                if (e.Args != null && e.Args.Length > 0)
                {
                    AppConfig.Instance.Start = new Config.Startup(e.Args);
                }
            }
            catch(CommandArgumentException ex)
            {
                MessageBox.Show(
                    string.Format("args error: {0}", string.Join(" ", ex.Command)),
                    "Argument Error",
                    MessageBoxButton.OK,
                    MessageBoxImage.Error
                    );
            }

            // Open window
            MainWindow window = new MainWindow();
            this.MainWindow = window;
            window.ShowDialog();

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
                //// Showing window
                //ErrorWindow errorWindow = new ErrorWindow(e.Exception);
                //errorWindow.ShowDialog();
                MessageBox.Show(
                    e.Exception.Message,
                    "Error",
                    MessageBoxButton.OK,
                    MessageBoxImage.Error
                    );
            }

            e.Handled = true;
        }

        #endregion Gahering all exceptions
    }
}
