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
            DisplayText(TextToDisplay.Text);
        }

        // Handle to Click event for the button.
        private void OnDisplayTextClick(object sender, EventArgs e)
        {
            DisplayText(TextToDisplay.Text);
        }
        
        // <SnippetTextPathGeometryHightlightSample2>
        // Display the text string and animate the ellipse to trace the text character outlines.
        public void DisplayText(string textToDisplay)
        {
            // Create a formatted text string.
            FormattedText formattedText = new FormattedText(
                textToDisplay,
                CultureInfo.GetCultureInfo("en-us"),
                FlowDirection.LeftToRight,
                new Typeface("Verdana"),
                96,
                System.Windows.Media.Brushes.Black);

            // Set the font weight to Bold for the formatted text.
            formattedText.SetFontWeight(FontWeights.Bold);

            // Build a geometry out of the formatted text.
            Geometry geometry = formattedText.BuildGeometry(new System.Windows.Point(0, 0));

            // Create a set of polygons by flattening the Geometry object.
            PathGeometry pathGeometry = geometry.GetFlattenedPathGeometry();

            // Supply the empty Path element in XAML with the PathGeometry in order to render the polygons.
            path.Data = pathGeometry;

            // Use the PathGeometry for the matrix animation,
            // allowing the ellipse to follow the path of the polygons.
            matrixAnimation.PathGeometry = pathGeometry;
        }
        // </SnippetTextPathGeometryHightlightSample2>

    }
}