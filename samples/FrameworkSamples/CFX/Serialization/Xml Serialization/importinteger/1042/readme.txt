SchemaImporterExtension ���� �������� ����
=============================================
     SchemaImporterExtension�� �ۼ��Ͽ� XML ��Ű�� ���� ������ string ��� long �� ulong���� �������� ����� ���� �ݴϴ�.


���� ��� ����
===============================
     �� ������ ������ ���� ��� �������� ����� �� �ֽ��ϴ�.
     C#


��� ������Ʈ�� ����Ͽ� ������ �����Ϸ���
=============================================
     1. ��� ������Ʈ â�� ���� Technologies\Serialization\Xml Serialization\SchemaImporterExtension\ImportInteger ���͸��� �̵��մϴ�.
     2. msbuild [Solution Filename]�� �Է��մϴ�.


Visual Studio�� ����Ͽ� ������ �����Ϸ���
=======================================
     1. Windows Ž���⸦ ���� Technologies\Serialization\Xml Serialization\SchemaImporterExtension\ImportInteger ���͸��� �̵��մϴ�.
     2. .sln(�ַ��) ������ �������� �� �� Ŭ���Ͽ� Visual Studio���� �ش� ������ ���ϴ�.
     3. [����] �޴����� [�ַ�� ����]�� �����մϴ�.
     ���� ���α׷��� �⺻������ \bin �Ǵ� \bin\Debug ���͸��� ����˴ϴ�.

     �� ������ ������ �� �߰��� ����� ������ ������ �����ϴ�.
     1.  ������� ���� ������ �̸��� �����մϴ�.
     2.  ������� GAC�� �߰��մϴ�.
     3.  schemas.xml.serialization/schemaImporterExtension ������ machine.config�� ������� �߰��մϴ�.


������ �����Ϸ���
=================
     1. ��� ������Ʈ�� Windows Ž���⸦ ����Ͽ� �� ���� ������ ���Ե� ���͸��� �̵��մϴ�.
     2. ����ٿ� [ExecutableFile]�� �Է��ϰų� Windows Ž���⿡�� [SampleExecutable] �������� �� �� Ŭ���Ͽ� ������ �����մϴ�.

     ���ѵ� ������ ����Ͽ� ������ ������ ���� ������ ������� GAC�� �߰��ϰ� machine.config�� �����ؾ� �ϹǷ� ������ ��ġ�Ϸ��� ������ ������ �ʿ��մϴ�.

     machine.config�� ���� ��Ʈ��:

     system.xml.serialization
     	schemaImporterExtensions
     		add name="RandomString" type="Microsoft.Samples.Xml.Serialization.SchemaImporterExtension.ImportInteger, ImportInteger, Version=0.0.0.0, Culture=neutral, PublicKeyToken=3c3789dee90b3265"
     	schemaImporterExtensions
     system.xml.serialization


����
=================
     1.  xsd.exe, wsdl.exe�� �����ϰų� xs:integer, xs:negativeInteger, xs:nonNegativeInteger, xs:positiveInteger �Ǵ� xs:nonPositiveInteger�� ����ϴ� WSDL�� �� ������ �߰��մϴ�.
2.  ������ Ŭ������ XML ��Ű�� ���� ���Ŀ� ���� string ��� long �Ǵ� ulong�� ����մϴ�.
