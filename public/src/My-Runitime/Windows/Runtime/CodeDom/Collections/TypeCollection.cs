/*System.Extensions License
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
*/

using System;
using System.Reflection;

namespace System.Extensions.CodeDom.Collections
{
	/// <summary>
	/// A collection of elements of type Type
	/// </summary>
	public class TypeCollection: System.Collections.CollectionBase
	{
		/// <summary>
		/// Initializes a new empty instance of the TypeCollection class.
		/// </summary>
		public TypeCollection()
		{
			// empty
		}

		/// <summary>
		/// Initializes a new instance of the TypeCollection class, containing elements
		/// copied from an array.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the new TypeCollection.
		/// </param>
		public TypeCollection(Type[] items)
		{
            AddRange(items);
		}

		/// <summary>
		/// Initializes a new instance of the TypeCollection class, containing elements
		/// copied from another instance of TypeCollection
		/// </summary>
		/// <param name="items">
		/// The TypeCollection whose elements are to be added to the new TypeCollection.
		/// </param>
		public TypeCollection(TypeCollection items)
		{
            AddRange(items);
		}

		/// <summary>
		/// Adds the elements of an array to the end of this TypeCollection.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the end of this TypeCollection.
		/// </param>
		public void AddRange(Type[] items)
		{
			foreach (Type item in items)
			{
                List.Add(item);
			}
		}

		/// <summary>
		/// Adds the elements of another TypeCollection to the end of this TypeCollection.
		/// </summary>
		/// <param name="items">
		/// The TypeCollection whose elements are to be added to the end of this TypeCollection.
		/// </param>
		public void AddRange(TypeCollection items)
		{
			foreach (Type item in items)
			{
                List.Add(item);
			}
		}

		/// <summary>
		/// Adds an instance of type Type to the end of this TypeCollection.
		/// </summary>
		/// <param name="value">
		/// The Type to be added to the end of this TypeCollection.
		/// </param>
		public void Add(Type value)
		{
            List.Add(value);
		}

		/// <summary>
		/// Determines whether a specfic Type value is in this TypeCollection.
		/// </summary>
		/// <param name="value">
		/// The Type value to locate in this TypeCollection.
		/// </param>
		/// <returns>
		/// true if value is found in this TypeCollection;
		/// false otherwise.
		/// </returns>
		public bool Contains(Type value)
		{
			return List.Contains(value);
		}

		/// <summary>
		/// Return the zero-based index of the first occurrence of a specific value
		/// in this TypeCollection
		/// </summary>
		/// <param name="value">
		/// The Type value to locate in the TypeCollection.
		/// </param>
		/// <returns>
		/// The zero-based index of the first occurrence of the _ELEMENT value if found;
		/// -1 otherwise.
		/// </returns>
		public int IndexOf(Type value)
		{
			return List.IndexOf(value);
		}

		/// <summary>
		/// Inserts an element into the TypeCollection at the specified index
		/// </summary>
		/// <param name="index">
		/// The index at which the Type is to be inserted.
		/// </param>
		/// <param name="value">
		/// The Type to insert.
		/// </param>
		public void Insert(int index, Type value)
		{
            List.Insert(index, value);
		}

		/// <summary>
		/// Gets or sets the Type at the given index in this TypeCollection.
		/// </summary>
		public virtual Type this[int index]
		{
			get
			{
				return (Type)List[index];
			}
			set
			{
                List[index] = value;
			}
		}

		/// <summary>
		/// Removes the first occurrence of a specific Type from this TypeCollection.
		/// </summary>
		/// <param name="value">
		/// The Type value to remove from this TypeCollection.
		/// </param>
		public void Remove(Type value)
		{
            List.Remove(value);
		}

		/// <summary>
		/// Type-specific enumeration class, used by TypeCollection.GetEnumerator.
		/// </summary>
		public class Enumerator: System.Collections.IEnumerator
		{
            private readonly System.Collections.IEnumerator wrapped;

            public Enumerator(TypeCollection collection)
			{
                wrapped = ((System.Collections.CollectionBase)collection).GetEnumerator();
			}

			public Type Current
			{
				get
				{
					return (Type) (wrapped.Current);
				}
			}

			object System.Collections.IEnumerator.Current
			{
				get
				{
					return (Type) (wrapped.Current);
				}
			}

			public bool MoveNext()
			{
				return wrapped.MoveNext();
			}

			public void Reset()
			{
                wrapped.Reset();
			}
		}

		/// <summary>
		/// Returns an enumerator that can iterate through the elements of this TypeCollection.
		/// </summary>
		/// <returns>
		/// An object that implements System.Collections.IEnumerator.
		/// </returns>        
		public new Enumerator GetEnumerator()
		{
			return new Enumerator(this);
		}
	}

}
