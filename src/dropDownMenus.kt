package dropDownMenus

import java.io.File
import java.util.*
import javax.swing.JComboBox


// class to quickly build a drop down list from a file. 
class DropDownList : JComboBox<String> {

    constructor(fileName: String) : super() {
        File(fileName).forEachLine { addItem(it) }
    }

    // empty constructor
    constructor()

}

