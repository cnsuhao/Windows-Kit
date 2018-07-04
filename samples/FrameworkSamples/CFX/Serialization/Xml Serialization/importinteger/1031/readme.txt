Beispiel "SchemaImporterExtension Import Integer"
=================================================
     Zeigt, wie Sie eine SchemaImporterExtension schreiben, um XML-Schemaganzzahltypen als "long" oder "ulong" anstatt als "string" zu importieren.


Sprachimplementierungen dieses Beispiels
========================================
     Dieses Beispiel ist in den folgenden Programmiersprachen verf�gbar:
     C#


So erstellen Sie das Beispiel mithilfe der Eingabeaufforderung
==============================================================
     1. �ffnen Sie das Eingabeaufforderungsfenster, und wechseln Sie zum Verzeichnis "Technologies\Serialization\Xml Serialization\SchemaImporterExtension\ImportInteger".
     2. Geben Sie "msbuild [Name der Projektmappendatei]" ein.


So erstellen Sie das Beispiel mithilfe von Visual Studio
========================================================
     1. �ffnen Sie das Eingabeaufforderungsfenster, und wechseln Sie zum Verzeichnis "Technologies\Serialization\Xml Serialization\SchemaImporterExtension\ImportInteger".
     2. Doppelklicken Sie auf das Symbol f�r die SLN-Datei (Projektmappe), um die Datei in Visual Studio zu �ffnen.
     3. W�hlen Sie im Men� "Erstellen" die Option "Projektmappe erstellen" aus.
     Die Anwendung wird im Standardverzeichnis "\bin" oder "\bin\debug" erstellt.

     Weitere Punkte, die Sie beim Erstellen des Beispiels beachten sollten:
     1. Erzeugen Sie einen starken Namen f�r die Assembly.
     2. F�gen Sie die Assembly dem GAC hinzu.
     3. F�gen Sie die Assembly in einem Abschnitt "schemas.xml.serialization/schemaImporterExtension" zu "machine.config" hinzu.


So f�hren Sie das Beispiel aus
==============================
     1. Wechseln Sie mithilfe der Eingabeaufforderung oder in Windows Explorer zu dem Verzeichnis, das die neue ausf�hrbare Datei enth�lt.
     2. Geben Sie an der Befehlszeile "[Ausf�hrbareDatei]" ein, oder doppelklicken Sie in Windows Explorer auf das Symbol f�r [BeispielAusf�hrbareDatei], um das Beispiel zu starten.

     Das Beispiel kann mit eingeschr�nkter Berechtigung erstellt werden. F�r das Installieren sind jedoch Administratorrechte erforderlich, da die Assembly dem GAC hinzugef�gt und "machine.config" bearbeitet werden muss.

     Beispieleintrag in "machine.config":

     system.xml.serialization
     	schemaImporterExtensions
     		add name="RandomString" type="Microsoft.Samples.Xml.Serialization.SchemaImporterExtension.ImportInteger, ImportInteger, Version=0.0.0.0, Culture=neutral, PublicKeyToken=3c3789dee90b3265"
     	schemaImporterExtensions
     system.xml.serialization


Hinweise
========
     1. F�hren Sie "xsd.exe", "wsdl.exe" oder "Webverweis hinzuf�gen" in WSDL aus, das xs:integer, xs:negativeInteger, xs:nonNegativeInteger, xs:positiveInteger oder xs:nonPositiveInteger verwendet.
2. Beachten Sie, dass die erzeugte Klasse "long" oder "ulong" anstelle von "string" f�r die XML-Schemaganzzahltypen verwendet.
