/// System.Extensions License
/// 
/// Copyright (c) 2004 Jonathan de Halleux, http://www.dotnetwiki.org
///
/// This software is provided 'as-is', without any express or implied warranty. 
/// In no event will the authors be held liable for any damages arising from 
/// the use of this software.
/// 
/// Permission is granted to anyone to use this software for any purpose, 
/// including commercial applications, and to alter it and redistribute it 
/// freely, subject to the following restrictions:
///
/// 1. The origin of this software must not be misrepresented; 
/// you must not claim that you wrote the original software. 
/// If you use this software in a product, an acknowledgment in the product 
/// documentation would be appreciated but is not required.
/// 
/// 2. Altered source versions must be plainly marked as such, 
/// and must not be misrepresented as being the original software.
///
///3. This notice may not be removed or altered from any source distribution.

using System;
using System.CodeDom;

namespace System.Extensions.CodeDom
{
	using System.Extensions.CodeDom.Doc;
	using System.Extensions.CodeDom.Collections;

	public class Declaration : ITypeDeclaration
	{
		private string name;
		private NameConformer conformer;
		private Documentation doc = new Documentation();
		private MemberAttributes attributes = MemberAttributes.Private;
		private CodeAttributeDeclarationCollection customAttributes = new CodeAttributeDeclarationCollection();

		internal Declaration(string name, NameConformer conformer)
		{
			if (name==null)
				throw new ArgumentNullException("name");
			if (conformer==null)
				throw new ArgumentNullException("conformer");
			this.name = name;
			this.conformer = conformer;
		}

		public String Name
		{
			get
			{
				return this.name;
			}
		}

		public virtual String FullName
		{
			get
			{
				return this.Name;
			}
		}

		public NameConformer Conformer
		{
			get
			{
				return this.conformer;
			}
		}

		public Documentation Doc
		{
			get
			{
				return this.doc;
			}
		}

		public MemberAttributes Attributes
		{
			get
			{
				return this.attributes;
			}
			set
			{
				this.attributes = value;
			}
		}

		public CodeAttributeDeclarationCollection CustomAttributes
		{
			get
			{
				return this.customAttributes;
			}
		}

		protected void ToCodeDom(CodeTypeMember ctm)
		{
			ctm.Attributes = this.Attributes;
			ctm.Name = this.Name;
			this.Doc.ToCodeDom(ctm.Comments);
			ctm.CustomAttributes.AddRange(this.customAttributes);
		}

		#region ITypeDeclaration Members

		public CodeTypeReference TypeReference
		{
			get
			{
				return new CodeTypeReference(this.name);
			}
		}

		#endregion
	}
}
