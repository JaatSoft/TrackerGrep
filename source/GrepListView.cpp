/*
 * Copyright (c) 1998-2007 Matthijs Hollemans
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 */

#include <Path.h>
#include <Entry.h>
#include "GrepListView.h"

class ResultItem : public BStringItem {
	public:

		ResultItem(entry_ref &ref) : BStringItem("", 0, false)
		{
			this->ref = ref;
			BEntry entry(&ref);
			BPath path(&entry);
			SetText(path.Path()); 
		}
	
		entry_ref ref;
};


GrepListView::GrepListView()
	: BOutlineListView(BRect(0, 0, 40, 80), "SearchResults", 
		B_MULTIPLE_SELECTION_LIST, B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_NAVIGABLE)
{
	// void
}
