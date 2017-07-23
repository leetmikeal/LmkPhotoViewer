namespace LmkPhotoViewer.Model
{
    using System;
    using LmkImageLib;
    using System.Text;

    public static class ApplicationInformation 
    {
        #region Property

        private static string contributor;
        public static string Contributor
        {
            get
            {
                if(contributor == null)
                {
                    StringBuilder b = new StringBuilder();
                    b.Append(@"Teppei Tamaki" + Environment.NewLine);
                    b.Append(@"");
                    contributor = b.ToString();
                }
                return contributor;
            }
        }

        private static string reference;
        public static string Reference
        {
            get
            {
                if(reference == null)
                {
                    StringBuilder b = new StringBuilder();
                    b.Append(@"SVG Rendering Engine" + Environment.NewLine);
                    b.Append(@"http://svg.codeplex.com" + Environment.NewLine);
                    b.Append(@"");
                    reference = b.ToString();
                }
                return reference;
            }
        }

        #endregion
    }

}
