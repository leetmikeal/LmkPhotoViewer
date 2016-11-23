using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace LmkPhotoViewer.Config
{
    /// <summary>
    /// User saved data
    /// </summary>
    [DataContract(Namespace = "")]
    public class Roaming : ObservableObject
    {
        public Roaming()
        {
        }

        #region data

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

        #endregion data
    }
}
