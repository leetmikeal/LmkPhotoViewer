using GalaSoft.MvvmLight;
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
            this.Start = new AppStartOption();
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

        private AppStartOption start;
        /// <summary>
        /// Startup options
        /// </summary>
        public AppStartOption Start
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


        #endregion configuration body
    }
}
