/**************************************************************************/
/*  learn_view.cpp                                                        */
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

#include "learn_view.h"
#include "core/io/file_access.h"
#include "core/io/json.h"
#include "core/variant/dictionary.h"
#include "core/variant/variant.h"
#include "scene/gui/box_container.h"
#include "scene/gui/label.h"
#include "scene/gui/scroll_container.h"

void LearnView::_init_GUI() {
	_init_labels();

	docs_container = memnew(BoxContainer());
	docs_container->set_name("DocsContainer");
	this->add_child(docs_container);

	// const Variant parsed_content = _parse_file_content();
	// _fill_lists(parsed_content);
}

void LearnView::_init_labels() {
	labels = memnew(HBoxContainer());
	labels->set_name("LabelsContainer");

	Label *docs_label = memnew(Label());
	docs_label->set_text("Documentation");
	labels->add_child(docs_label);

	Label *tut_label = memnew(Label());
	tut_label->set_text("Tutorials");
	labels->add_child(tut_label);

	Label *plugin_label = memnew(Label());
	plugin_label->set_text("Plugins");
	labels->add_child(plugin_label);

	Label *templates_label = memnew(Label());
	templates_label->set_text("Templates");
	labels->add_child(templates_label);

	this->add_child(labels);
}

void LearnView::_init_lists() {
	_init_plugins_container();
	_init_templates_container();
	_init_tuts_container();

	lists = memnew(HBoxContainer());
	lists->set_name("ListsContainer");

	lists->add_child(tuts_container);
	lists->add_child(plugins_container);
	lists->add_child(templates_container);
}

void LearnView::_init_tuts_container() {
	tuts_container = memnew(ScrollContainer());
	tuts_container->set_name("Tutorials");
}

void LearnView::_init_plugins_container() {
	plugins_container = memnew(ScrollContainer());
	plugins_container->set_name("Plugins");
}

void LearnView::_init_templates_container() {
	templates_container = memnew(ScrollContainer());
	templates_container->set_name("Templates");
}

Variant LearnView::_parse_file_content() const {
	Ref<FileAccess> file = FileAccess::open("", FileAccess::READ);

	if (!file.is_valid()) {
		ERR_PRINT("Failed to open JSON file.");
		return NULL;
	}
	const String content = file->get_as_text();
	file->close();

	Ref<JSON> json;
	json.instantiate();
	Error err = json->parse_string(content);
	if (err != OK) {
		ERR_PRINT("JSON parse error");
	}

	return json->get_data();
}

void LearnView::_fill_lists(const Variant &content) {
	if (content.get_type() == Variant::DICTIONARY) {
		Dictionary dict = content;
		//TODO: Fill the vector variables with the correct data.
	}
}
