using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace LmkImageLib
{
    /// <summary>
    /// Generic image class
    /// 
    /// 8-bit multi channel
    /// </summary>
    [DataContract(Name = "")]
    public class LmkImage
    {
        private LmkImageClrLib.LmkImage body;

    }
}
