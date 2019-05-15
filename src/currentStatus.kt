package currentStatus

import dropDownMenus.*
import java.awt.event.ActionListener
import java.io.File
import java.util.*
import javax.swing.Box
import javax.swing.BoxLayout
import javax.swing.JComboBox

// this class is a GUI component made of other components in the program.
class CurrentStatusBar : Box {

    // the current status will be the gamemode, stage, weaponType, weapon, number of kills, number special deploys, and enter button


    // playing {gamemode} on {stage} with {weapon type} {weapon}: kills {kills}, special deploys {special deploys} [enter button]


    var stageDropDown = DropDownList("stages.txt")
    var gamemodeDropDown = DropDownList("gamemodes.txt")
    var weaponTypesDropDown = DropDownList("weaponTypes.txt")
    var generalWeaponDropDown = JComboBox<String>() // to be reassigned to other lists of weapons depending on the current weaponTypeDropDown selection

    //private var stages = Vector<String>()
    private var brellas = Vector<String>()
    private var chargers = Vector<String>()
    private var dualies = Vector<String>()
    private var rollers = Vector<String>()
    private var shooters = Vector<String>()
    private var sloshers = Vector<String>()
    private var splatlings = Vector<String>()
    //private var weaponTypes = Vector<String>()



    // different types of weapons drop-downs




    constructor() : super(BoxLayout.X_AXIS) {
        // setup the layout of the box that the drop-down menus will be in.


        weaponTypesDropDown.addActionListener(ActionListener {
            // change the contents of the GeneralWeaponDropDown object.

            var tempFile = when (weaponTypesDropDown.selectedItem) {

                "Brellas" -> File("brellas.txt")
                "Chargers" -> File("chargers.txt")
                "Dualies" -> File("dualies.txt")
                "Rollers" -> File("rollers.txt")
                "Shooters" -> File("shooters.txt")
                "Sloshers" -> File("sloshers.txt")
                "Splatlings" -> File("splatlings.txt")

                else -> null
            }

            // if the file is not null, clear the comboBox and set it to the new weaponType.
            tempFile?.let {

                generalWeaponDropDown.removeAllItems()

                tempFile.forEachLine { generalWeaponDropDown.addItem(it) }

            }


        })



        this.add(weaponTypesDropDown)

        weaponTypesDropDown.layout = null
        weaponTypesDropDown.isVisible = true

// load all the stages and weapon types into vectors
        //File("stages.txt").forEachLine { stages.add(it) }
        File("brellas.txt").forEachLine { brellas.add(it) }
        File("chargers.txt").forEachLine { chargers.add(it) }
        File("dualies.txt").forEachLine { dualies.add(it) }
        File("rollers.txt").forEachLine { rollers.add(it) }
        File("shooters.txt").forEachLine { shooters.add(it) }
        File("sloshers.txt").forEachLine { sloshers.add(it) }
        File("splatlings.txt").forEachLine { splatlings.add(it) }

        // initalize the weaponTypes vector
//        weaponTypes.add("Brellas")
//        weaponTypes.add("Chargers")
//        weaponTypes.add("Dualies")
//        weaponTypes.add("Rollers")
//        weaponTypes.add("Shooters")
//        weaponTypes.add("Sloshers")
//        weaponTypes.add("Splatlings")


    }



}