using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace LmkPhotoViewer
{
    /// <summary>
    /// Startup options
    /// </summary>
    public class AppStartOption : ObservableObject
    {
        public AppStartOption(string[] args = null)
        {
            if (args == null)
                return;

            this.OriginalArgs = args;

            InputArguments(args);
        }

        /// <summary>
        /// Analysing command-line arguments
        /// </summary>
        /// <param name="args">command-line arguments</param>
        private void InputArguments(string[] args)
        {
            ArgsState state = ArgsState.FilePath;

            foreach(var arg in args)
            {
                if (state == ArgsState.None)
                {
                }

                switch(state)
                {
                    case ArgsState.FilePath:
                        {
                            this.FilePath = arg;
                            state = ArgsState.None;
                            continue;
                        }
                }

                throw new CommandArgumentException();
            }

            if(state != ArgsState.None)
                throw new CommandArgumentException();
        }

        /// <summary>
        /// Argument analysing status
        /// </summary>
        private enum ArgsState
        {
            None,
            FilePath,
        }

        #region 設定

        private string[] originalArgs;

        /// <summary>
        /// Startup command-line arguments
        /// </summary>
        public string[] OriginalArgs
        {
            get
            {
                return originalArgs;
            }
            set
            {
                originalArgs = value;
                RaisePropertyChanged(() => OriginalArgs);
            }
        }

        private string filePath;

        /// <summary>
        /// Opening file path
        /// </summary>
        public string FilePath
        {
            get
            {
                return filePath;
            }
            set
            {
                filePath = value;
                RaisePropertyChanged(() => FilePath);
            }
        }

        #endregion 設定
    }
}
