using GalaSoft.MvvmLight;
using LmkPhotoViewer.Config;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LmkPhotoViewer
{
    /// <summary>
    /// Application system configuration
    /// </summary>
    public class AppConfig : ObservableObject
    {
        private AppConfig()
        {
            this.Start = new Startup();
        }

        #region singleton instance
        private static AppConfig instance;
        public static AppConfig Instance
        {
            get
            {
                if (instance == null)
                    instance = new AppConfig();
                return instance;
            }
        }
        #endregion singleton instance

        #region configuration body

        private Startup start;
        /// <summary>
        /// Startup options
        /// no serialize, temporal data
        /// </summary>
        public Startup Start
        {
            get
            {
                return start;
            }
            set
            {
                start = value;
                RaisePropertyChanged(() => Start);
            }
        }

        private Roaming roaming;
        /// <summary>
        /// Startup options
        /// no serialize, temporal data
        /// </summary>
        public Roaming Roaming
        {
            get
            {
                return roaming;
            }
            set
            {
                roaming = value;
                RaisePropertyChanged(() => Roaming);
            }
        }

        #endregion configuration body
    }
}
