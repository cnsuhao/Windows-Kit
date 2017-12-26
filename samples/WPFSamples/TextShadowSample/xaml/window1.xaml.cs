using System;
using System.Globalization;
using System.Windows;
using System.Windows.Media;

namespace SDKSample
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>

    public partial class Window1 : Window
    {     
        public Window1()
        {
            InitializeComponent();
        }

        // Handle the Click event for the button.
        public void OnDisplayTextClick(object sender, EventArgs e)
        {
            textblockMaster.Text = TextToDisplay.Text;
        }
    }
}