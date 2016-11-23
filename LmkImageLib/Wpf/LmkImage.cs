using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace LmkImageLib.Wpf
{
    /// <summary>
    /// image type extensions
    /// </summary>
    public static class LmkImageExtension
    {
        public static WriteableBitmap ToWriteableBitmap(this LmkImage image)
        {
            int dpi = 96;
            return new WriteableBitmap(image.Height, image.Height, dpi, dpi, PixelFormats.Bgr24, null);
        }
    }
}
