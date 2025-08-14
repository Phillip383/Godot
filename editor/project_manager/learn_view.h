# pragma once

#include "scene/gui/box_container.h"
#include "scene/gui/panel_container.h"
#include "scene/gui/scroll_container.h"

class HBoxContainer;
class Variant;


struct LearnItem {
    String tooltip = "";
    String url = "";
    String icon = "";
};

class LearnView : public PanelContainer{

public:

    LearnView(){
        _init_GUI();
    }

private:

    BoxContainer* docs_container = nullptr;
    HBoxContainer* labels = nullptr;
    HBoxContainer* lists = nullptr;
    ScrollContainer* tuts_container = nullptr;
    ScrollContainer* plugins_container = nullptr;
    ScrollContainer* templates_container = nullptr;

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

    Variant _parse_file_content() const;
    void _fill_lists(const Variant& content);
};