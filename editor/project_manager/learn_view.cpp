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
#include "core/error/error_macros.h"
#include "core/io/file_access.h"
#include "core/io/json.h"
#include "core/math/math_defs.h"
#include "core/object/class_db.h"
#include "core/variant/dictionary.h"
#include "core/variant/variant.h"
#include "editor/editor_node.h"
#include "editor/editor_string_names.h"
#include "editor/themes/editor_scale.h"
#include "scene/gui/box_container.h"
#include "scene/gui/button.h"
#include "scene/gui/color_rect.h"
#include "scene/gui/control.h"
#include "scene/gui/label.h"
#include "scene/gui/panel.h"
#include "scene/gui/panel_container.h"
#include "scene/gui/scroll_container.h"
#include "scene/resources/style_box_flat.h"

void LearnView::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_notification"), &LearnView::_notification);
}

void LearnView::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_ENTER_TREE:
			_init_GUI();
			break;
		case NOTIFICATION_POSTINITIALIZE:
			break;
	}
}

void LearnView::_init_GUI() {
	main_vb_container = memnew(VBoxContainer());
	this->add_child(main_vb_container);

	_init_content();

	PanelContainer *contents_bg = memnew(PanelContainer);
	main_vb_container->add_child(contents_bg);
	contents_bg->set_v_size_flags(Control::SIZE_EXPAND_FILL);
	contents_bg->add_theme_style_override(SceneStringName(panel), get_theme_stylebox(SNAME("project_list"), SNAME("ProjectManager")));

	ScrollContainer *contents_scroll = memnew(ScrollContainer);

	contents_scroll->set_horizontal_scroll_mode(ScrollContainer::SCROLL_MODE_DISABLED);
	contents_scroll->set_vertical_scroll_mode(ScrollContainer::SCROLL_MODE_SHOW_ALWAYS);

	Label *test = memnew(Label);
	test->set_text("Hello");
	contents_scroll->add_child(test);
	contents_bg->add_child(contents_scroll);

	_init_templates();
	_init_tuts();
	_init_plugins();
	// const Variant parsed_content = _parse_file_content();
	// _fill_lists(parsed_content);
}

void LearnView::_init_content() {
	content_buttons_container = memnew(HBoxContainer());
	content_buttons_container->set_alignment(BoxContainer::ALIGNMENT_CENTER);
	content_buttons_container->set_name("LabelsContainer");
	main_vb_container->add_child(content_buttons_container);

	Button *docs_button = memnew(Button());
	docs_button->set_text("Documentation");
	content_buttons_container->add_child(docs_button);

	Button *tut_button = memnew(Button());
	tut_button->set_text("Tutorials");
	content_buttons_container->add_child(tut_button);

	Button *plugin_button = memnew(Button());
	plugin_button->set_text("Plugins");
	content_buttons_container->add_child(plugin_button);

	Button *templates_button = memnew(Button());
	templates_button->set_text("Templates");
	content_buttons_container->add_child(templates_button);
}

void LearnView::_access_docs() {
	//TODO: send the user to the docs when button is clicked.
}

void LearnView::_init_tuts() {
}

void LearnView::_init_plugins() {
}

void LearnView::_init_templates() {
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
