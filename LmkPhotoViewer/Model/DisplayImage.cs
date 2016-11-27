namespace LmkPhotoViewer.Model
{
    using System;
    using LmkImageLib;

    public class DisplayImage : ModelBase
    {
        public DisplayImage(LmkImage source)
        {
            this.SourceType = DisplayImageSourceType.None;
            this.FilePath = "";
            this.FileInfo = null;
            this.Source = source;
        }

        public DisplayImage(string filePath)
        {
            this.SourceType = DisplayImageSourceType.File;
            this.SetImage(filePath);
        }

        private void SetImage(string filePath)
        {
            this.FilePath = filePath;
            if (System.IO.File.Exists(this.FilePath))
            {
                this.FileInfo = new FileInfo(filePath);
                this.Source = new LmkImage(filePath);
            }
            else
            {
                this.FileInfo = null;
                this.Source = null;
            }
        }

        private LmkImage source;

        public LmkImage Source
        {
            get
            {
                return source;
            }
            private set
            {
                source = value;
                RaisePropertyChanged(() => Source);
            }
        }

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

        private FileInfo fileInfo;

        public FileInfo FileInfo
        {
            get
            {
                return fileInfo;
            }
            private set
            {
                fileInfo = value;
                RaisePropertyChanged(() => FileInfo);
            }
        }

        private DisplayImageSourceType sourceType;

        public DisplayImageSourceType SourceType
        {
            get
            {
                return sourceType;
            }
            private set
            {
                sourceType = value;
                RaisePropertyChanged(() => SourceType);
            }
        }

        public void Refresh()
        {
            this.SetImage(this.FilePath);
        }
    }

    public enum DisplayImageSourceType
    {
        None,
        File,
    }
}
