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

namespace System.Extensions.CodeDom.Statements
{
	using System.Extensions.CodeDom.Collections;
	using System.Extensions.CodeDom.Expressions;
	/// <summary>
	/// Summary description for IterationStatement.
	/// </summary>
	public class IterationStatement : Statement
	{
		private Statement initStatement;
		private Statement incrementStatement;
		private Expression testExpression;
		private StatementCollection statements = new StatementCollection();

		public IterationStatement(Statement initStatement, Expression testExpression, Statement incrementStatement)
		{
			if (testExpression==null)
				throw new ArgumentNullException("testExpression");

			this.initStatement = initStatement;
			this.testExpression = testExpression;
			this.incrementStatement = incrementStatement;
		}

		public StatementCollection Statements
		{
			get
			{
				return this.statements;
			}
		}

		public override void ToCodeDom(CodeStatementCollection statements)
		{
			CodeStatement init = null;
			CodeStatement increment = null;

			if (this.initStatement!=null)
			{
				CodeStatementCollection col = new CodeStatementCollection();
				this.initStatement.ToCodeDom(col);
				init = col[0];
			}

			if (this.incrementStatement!=null)
			{
				CodeStatementCollection col = new CodeStatementCollection();
				this.incrementStatement.ToCodeDom(col);
				increment = col[0];
			}

			statements.Add(
				new CodeIterationStatement(
					init,
					this.testExpression.ToCodeDom(),
					increment,
					this.statements.ToCodeDomArray()
					)
				);
		}

	}
}
