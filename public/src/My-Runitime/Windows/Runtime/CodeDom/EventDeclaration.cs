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
	/// <summary>
	/// Summary description for EventDeclaration.
	/// </summary>
	public class EventDeclaration : MemberDeclaration
	{
		private ITypeDeclaration type;

		internal EventDeclaration(string name, Declaration declaringType, ITypeDeclaration type)
			:base(name,declaringType)
		{
			if (type==null)
				throw new ArgumentNullException("type");
			this.type = type;
			this.Attributes = MemberAttributes.Public;
		}

		public ITypeDeclaration Type
		{
			get
			{
				return this.type;
			}
		}

		public override CodeTypeMember ToCodeDom()
		{
			CodeMemberEvent e = new CodeMemberEvent();
			base.ToCodeDom(e);
			e.Name  = this.Conformer.NormalizeMember(this.Name,this.Attributes);
			e.Type = this.Type.TypeReference;

			return e;
		}
	}
}
