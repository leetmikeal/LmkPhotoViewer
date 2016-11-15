using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace LmkImageLib
{
    /// <summary>
    /// region, same as 1-bit image
    /// </summary>
    [DataContract(Name = "")]
    public class LmkRegion
    {
        private LmkImageClrLib.LmkRegion body;

    }
}
