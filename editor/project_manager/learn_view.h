/**************************************************************************/
/*  learn_view.h                                                          */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include "editor/editor_node.h"
#include "scene/gui/box_container.h"
#include "scene/gui/panel_container.h"
#include "scene/gui/scroll_container.h"

class HBoxContainer;
class Variant;
class ColorRect;

struct LearnItem {
	String tooltip = "";
	String url = "";
	String icon = "";
};

class LearnView : public PanelContainer {
	GDCLASS(LearnView, PanelContainer);

protected:
	static void _bind_methods();

public:
	LearnView() {
		_init_GUI();
	}

	void _notification(int p_what);

private:
	VBoxContainer *main_container = nullptr;
	BoxContainer *docs_container = nullptr;
	HBoxContainer *labels = nullptr;
	HBoxContainer *lists = nullptr;
	ScrollContainer *tuts_container = nullptr;
	ScrollContainer *plugins_container = nullptr;
	ScrollContainer *templates_container = nullptr;

	Vector<LearnItem> docs[1];
	Vector<LearnItem> tuts[10];
	Vector<LearnItem> plugins[10];
	Vector<LearnItem> templates[10];

	void _init_GUI();
	void _init_labels();
	void _init_lists();
	void _init_tuts_container();
	void _init_plugins_container();
	void _init_templates_container();

	ColorRect *_create_background(const Color &color) const;
	Variant _parse_file_content() const;
	void _fill_lists(const Variant &content);
};
