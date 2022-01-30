using Microsoft.Toolkit.Mvvm.Messaging.Messages;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LmkPhotoViewer.Messages
{
    public class ActionMessage: RequestMessage<string>
    {
        public ActionMessage(string action)
        {
            this.Reply(action);
        }
    }
}
