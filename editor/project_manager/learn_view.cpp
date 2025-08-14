#include "learn_view.h"
#include "core/io/file_access.h"
#include "core/io/json.h"
#include "core/variant/dictionary.h"
#include "core/variant/variant.h"
#include "scene/gui/box_container.h"
#include "scene/gui/label.h"
#include "scene/gui/scroll_container.h"


void LearnView::_init_GUI(){
    
    _init_labels();

    docs_container = memnew(BoxContainer());
    docs_container->set_name("DocsContainer");
    this->add_child(docs_container);
    
    // const Variant parsed_content = _parse_file_content();
    // _fill_lists(parsed_content);
}

void LearnView::_init_labels(){
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

void LearnView::_init_lists(){

    _init_plugins_container();
    _init_templates_container();
    _init_tuts_container();

    lists = memnew(HBoxContainer());
    lists->set_name("ListsContainer");
    
    lists->add_child(tuts_container);
    lists->add_child(plugins_container);
    lists->add_child(templates_container);
    
}

void LearnView::_init_tuts_container(){
    tuts_container = memnew(ScrollContainer());
    tuts_container->set_name("Tutorials");
}

void LearnView::_init_plugins_container(){
    plugins_container = memnew(ScrollContainer());
    plugins_container->set_name("Plugins");
}

void LearnView::_init_templates_container(){
    templates_container = memnew(ScrollContainer());
    templates_container->set_name("Templates");
}

Variant LearnView::_parse_file_content() const{
    Ref<FileAccess> file = FileAccess::open("", FileAccess::READ);
    
    if(!file.is_valid()){
        ERR_PRINT("Failed to open JSON file.");
        return NULL;
    }
    const String content = file->get_as_text();
    file->close();
    
    Ref<JSON> json;
    json.instantiate();
    Error err = json->parse_string(content);
    if(err != OK){
        ERR_PRINT("JSON parse error");
    }

    return json->get_data();
}    

void LearnView::_fill_lists(const Variant& content){
    if(content.get_type() == Variant::DICTIONARY){
        Dictionary dict = content;
        //TODO: Fill the vector variables with the correct data.
    }
}