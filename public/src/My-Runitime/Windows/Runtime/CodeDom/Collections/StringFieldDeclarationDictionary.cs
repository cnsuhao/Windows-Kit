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

namespace System.Extensions.CodeDom.Collections
{
	using System.Extensions.CodeDom;
	/// <summary>
	/// A dictionary with keys of type String and values of type FieldDeclaration
	/// </summary>
	public class StringFieldDeclarationDictionary: System.Collections.DictionaryBase
	{
		/// <summary>
		/// Initializes a new empty instance of the StringFieldDeclarationDictionary class
		/// </summary>
		public StringFieldDeclarationDictionary()
		{
			// empty
		}

		/// <summary>
		/// Gets or sets the FieldDeclaration associated with the given String
		/// </summary>
		/// <param name="key">
		/// The String whose value to get or set.
		/// </param>
		public virtual FieldDeclaration this[String key]
		{
			get
			{
				return (FieldDeclaration) this.Dictionary[key];
			}
		}

		/// <summary>
		/// Adds an element with the specified key and value to this StringFieldDeclarationDictionary.
		/// </summary>
		/// <param name="key">
		/// The String key of the element to add.
		/// </param>
		/// <param name="value">
		/// The FieldDeclaration value of the element to add.
		/// </param>
		public virtual void Add(FieldDeclaration value)
		{
			this.Dictionary.Add(value.Name, value);
		}

		/// <summary>
		/// Determines whether this StringFieldDeclarationDictionary contains a specific key.
		/// </summary>
		/// <param name="key">
		/// The String key to locate in this StringFieldDeclarationDictionary.
		/// </param>
		/// <returns>
		/// true if this StringFieldDeclarationDictionary contains an element with the specified key;
		/// otherwise, false.
		/// </returns>
		public virtual bool Contains(String key)
		{
			return this.Dictionary.Contains(key);
		}

		/// <summary>
		/// Determines whether this StringFieldDeclarationDictionary contains a specific key.
		/// </summary>
		/// <param name="key">
		/// The String key to locate in this StringFieldDeclarationDictionary.
		/// </param>
		/// <returns>
		/// true if this StringFieldDeclarationDictionary contains an element with the specified key;
		/// otherwise, false.
		/// </returns>
		public virtual bool ContainsKey(String key)
		{
			return this.Dictionary.Contains(key);
		}

		/// <summary>
		/// Determines whether this StringFieldDeclarationDictionary contains a specific value.
		/// </summary>
		/// <param name="value">
		/// The FieldDeclaration value to locate in this StringFieldDeclarationDictionary.
		/// </param>
		/// <returns>
		/// true if this StringFieldDeclarationDictionary contains an element with the specified value;
		/// otherwise, false.
		/// </returns>
		public virtual bool ContainsValue(FieldDeclaration value)
		{
			return ContainsKey(value.Name);
		}

		/// <summary>
		/// Removes the element with the specified key from this StringFieldDeclarationDictionary.
		/// </summary>
		/// <param name="key">
		/// The String key of the element to remove.
		/// </param>
		public virtual void Remove(String key)
		{
			this.Dictionary.Remove(key);
		}

		/// <summary>
		/// Gets a collection containing the keys in this StringFieldDeclarationDictionary.
		/// </summary>
		public virtual System.Collections.ICollection Keys
		{
			get
			{
				return this.Dictionary.Keys;
			}
		}

		/// <summary>
		/// Gets a collection containing the values in this StringFieldDeclarationDictionary.
		/// </summary>
		public virtual System.Collections.ICollection Values
		{
			get
			{
				return this.Dictionary.Values;
			}
		}
	}

}
