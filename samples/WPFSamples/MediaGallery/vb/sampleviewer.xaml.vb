 'This is a list of commonly used namespaces for a window.
Imports System
Imports System.Windows
Imports System.Windows.Controls
Imports System.Windows.Documents
Imports System.Windows.Navigation
Imports System.Windows.Shapes
Imports System.Windows.Data
Imports System.Windows.Media.Media3D
Imports System.Windows.Media.Animation
Imports System.Windows.Media

Namespace SDKSample

    '/ <summary>
    '/ Interaction logic for SampleViewer.xaml
    '/ </summary>

    Class SampleViewer
        Inherits Window
        '
        'ToDo: Error processing original source shown below
        '
        '    public partial class SampleViewer : Window
        '------------^--- 'class', 'struct', 'interface' or 'delegate' expected
        '
        'ToDo: Error processing original source shown below
        '
        '    public partial class SampleViewer : Window
        '--------------------^--- Syntax error: ';' expected
        Public Sub New()
            InitializeComponent()

        End Sub 'New 
    End Class 'SampleViewer
End Namespace 'SDKSample
