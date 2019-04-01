package currentStatus

import dropDownMenus.*
import javax.swing.JComboBox

// this class is a GUI component made of other components in the program.
class CurrentStatus {

    // the current status will be the gamemode, stage, weaponType, weapon, number of kills, number special deploys, and enter button

    var StageDropDown = DropDownList("stages.txt")
    var GamemodeDropDown = DropDownList("gamemodes.txt")
    var WeaponTypesDropDown = DropDownList("weaponTypes.txt")
    var GeneralWeaponDropDown = JComboBox<String>() // to be reassigned to other lists of weapons depending on the current weaponTypeDropDown selection

    // different types of weapons drop-downs




    constructor() {
        // setup the layout of the box that the drop-down menus will be in.




    }


}