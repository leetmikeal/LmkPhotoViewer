using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using LmkImageLib;

namespace LmkImageLib.Wpf
{
    /// <summary>
    /// image type extensions
    /// </summary>
    public static class LmkImageExtension
    {
        public unsafe static WriteableBitmap ToWriteableBitmap(this LmkImage image)
        {
            int width = image.Width;
            int height = image.Height;
            int size = width * height;
            //int dpiX = image.DpiX;
            //int dpiY = image.DpiY;
            double dpiX = 96;
            double dpiY = 96;
            if (image.Channel.Length == 1)
            {
                IntPtr data = image.Channel[0].Data;
                byte[] byteArray = new byte[size];
                System.Runtime.InteropServices.Marshal.Copy(data, byteArray, 0, size);

                var pixelFormat = PixelFormats.Gray8;
                var stride = width;
                var bitmap = BitmapImage.Create(width, height, dpiX, dpiY, pixelFormat, null, byteArray, stride);
                WriteableBitmap wbm = new WriteableBitmap(bitmap);
                return wbm;
                //return new WriteableBitmap(width, height, dpiX, dpiY, PixelFormats.Bgr24, null);
            }
            else if (image.Channel.Length == 3)
            {
                IntPtr dataR = image.Channel[0].Data;
                IntPtr dataG = image.Channel[1].Data;
                IntPtr dataB = image.Channel[2].Data;

                byte[] byteArray = new byte[size * 3];
                fixed (byte* ptr = &byteArray[0])
                {
                    LmkOperatorSet.ConvByte3to1((byte*)dataR, (byte*)dataG, (byte*)dataB, ptr, size);
                }

                var pixelFormat = PixelFormats.Bgr24;
                var stride = width * 3;
                var bitmap = BitmapImage.Create(width, height, dpiX, dpiY, pixelFormat, null, byteArray, stride);
                WriteableBitmap wbm = new WriteableBitmap(bitmap);
                return wbm;
                //return new WriteableBitmap(width, height, dpiX, dpiY, PixelFormats.Bgr24, null);
            }
            //else if(image.Channel.Length == 3)
            //{
            //    IntPtr dataR = image.Channel[0].Data;
            //    IntPtr dataG = image.Channel[1].Data;
            //    IntPtr dataB = image.Channel[2].Data;
            //    byte[] byteArrayR = new byte[size];
            //    System.Runtime.InteropServices.Marshal.Copy(dataR, byteArrayR, 0, size);
            //    System.Runtime.InteropServices.Marshal.Copy(dataG, byteArrayG, 0, size);
            //    System.Runtime.InteropServices.Marshal.Copy(dataB, byteArrayB, 0, size);

            //}

            throw new NotImplementedException();
        }
    }
}
