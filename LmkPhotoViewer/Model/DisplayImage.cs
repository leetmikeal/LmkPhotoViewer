using LmkImageLib;

namespace LmkPhotoViewer.Model.Controls
{
    public class DisplayImage : ModelBase
    {
        public DisplayImage(LmkImage source)
        {
            this.SourceType = DisplayImageSourceType.None;
            this.FilePath = "";
            this.Source = source;
        }

        public DisplayImage(string filePath)
        {
            this.SourceType = DisplayImageSourceType.File;
            this.FilePath = filePath;
            this.Source = new LmkImage(filePath);
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

    }

    public enum DisplayImageSourceType
    {
        None,
        File,
    }
}
