namespace LmkPhotoViewer.Model
{
    using System;
    using LmkImageLib;

    public class FileInfo : ModelBase
    {
        public FileInfo(string filePath)
        {
            this.FilePath = filePath;

            if (System.IO.File.Exists(this.FilePath))
            {
                this.Info = new System.IO.FileInfo(FilePath);
                this.UpdateDateTimeCached = this.Info.LastWriteTime;
            }
        }

        #region Property

        private string filePath;

        public string FilePath
        {
            get
            {
                return filePath;
            }
            private set
            {
                filePath = value;
                RaisePropertyChanged(() => FilePath);
            }
        }

        private DateTime updateDateTimeCached;

        public DateTime UpdateDateTimeCached
        {
            get
            {
                return updateDateTimeCached;
            }
            private set
            {
                updateDateTimeCached = value;
                RaisePropertyChanged(() => UpdateDateTimeCached);
            }
        }

        private System.IO.FileInfo info;

        public System.IO.FileInfo Info
        {
            get
            {
                return info;
            }
            private set
            {
                info = value;
                RaisePropertyChanged(() => Info);
            }
        }

        #endregion

        #region Method

        /// <summary>
        /// If Updated, return true.
        /// </summary>
        /// <returns>judge updated or not</returns>
        public bool? CheckUpdated()
        {
            this.Info.Refresh();

            // removed
            if (!this.Info.Exists)
                return null;

            // update 
            if(this.UpdateDateTimeCached != this.Info.LastWriteTime)
            {
                this.UpdateDateTimeCached = this.Info.LastWriteTime;
                return true;
            }

            return false;
        }

        #endregion
    }

}
