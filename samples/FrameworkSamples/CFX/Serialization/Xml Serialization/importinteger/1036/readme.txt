Exemple SchemaImporterExtension Import Integer
=============================================
     Montre comment �crire un SchemaImporterExtension pour importer les types d'entiers du sch�ma XML sous la forme long et ulong au lieu de string.


Langages d'impl�mentation de l'exemple
===============================
     Les impl�mentations de cet exemple sont disponibles dans les langages suivants :
     C#


Pour g�n�rer l'exemple � partir de l'invite de commandes
=============================================
     1. Ouvrez la fen�tre d'invite de commandes et acc�dez au r�pertoire Technologies\Serialization\Xml Serialization\SchemaImporterExtension\ImportInteger.
     2. Tapez msbuild [Nom de fichier de la solution].


Pour g�n�rer l'exemple � l'aide de Visual Studio
=======================================
     1. Ouvrez l'Explorateur Windows et acc�dez au r�pertoire Technologies\Serialization\Xml Serialization\SchemaImporterExtension\ImportInteger.
     2. Double-cliquez sur l'ic�ne du fichier solution (.sln) pour l'ouvrir dans Visual Studio.
     3. Dans le menu G�n�rer, s�lectionnez G�n�rer la solution.
     L'application sera g�n�r�e dans le r�pertoire par d�faut \bin ou \bin\Debug.

     �l�ments suppl�mentaires � prendre en compte lors de la g�n�ration de cet exemple :
     1.  G�n�rez un nom fort pour l'assembly
     2.  Ajoutez l'assembly au GAC
     3.  Ajoutez l'assembly � machine.config dans une section schemas.xml.serialization/schemaImporterExtension


Pour ex�cuter l'exemple
=================
     1. Acc�dez au r�pertoire qui contient le nouveau fichier ex�cutable � l'aide de l'invite de commandes ou de l'Explorateur Windows.
     2. Tapez [Nom_fichier_exe] � l'invite de commandes ou double-cliquez sur l'ic�ne de [Nom_Exe_Exemple] pour l'ex�cuter � partir de l'Explorateur Windows.

     L'exemple peut �tre g�n�r� avec des autorisations limit�es, mais l'installation requiert des privil�ges d'administrateur, car l'assembly doit �tre ajout� au GAC et machine.config doit �tre modifi�.

     Exemple d'entr�e dans machine.config :

     system.xml.serialization
     	schemaImporterExtensions
     		add name="RandomString" type="Microsoft.Samples.Xml.Serialization.SchemaImporterExtension.ImportInteger, ImportInteger, Version=0.0.0.0, Culture=neutral, PublicKeyToken=3c3789dee90b3265"
     	schemaImporterExtensions
     system.xml.serialization


Notes
=================
     1.  Ex�cutez xsd.exe, wsdl.exe ou Ajouter une r�f�rence Web pour WSDL qui utilise xs:integer, xs:negativeInteger, xs:nonNegativeInteger, xs:positiveInteger ou xs:nonPositiveInteger
2.  Remarquez que la classe g�n�r�e utilise long ou ulong au lieu de string pour les types d'entiers du sch�ma XML

