package window

import java.util.*
import javax.swing.*
import java.io.File
import java.awt.event.*
import dropDownMenus.*
import currentStatus.*
import com.google.gson.Gson
import kotlin.text.*

class MyWindow : ActionListener {

    // fields and data members

    private var brellas = Vector<String>()
    private var chargers = Vector<String>()
    private var dualies = Vector<String>()
    private var rollers = Vector<String>()
    private var shooters = Vector<String>()
    private var sloshers = Vector<String>()
    private var splatlings = Vector<String>()

    private var weaponTypes = DropDownList("weaponTypes.txt")
    private var generalWeaponDropDown = DropDownList()
    private var gameModes = DropDownList("gamemodes.txt")
    private var stageDropDown = DropDownList("stages.txt")

    private var killsText = JTextField("Kills")
    private var specialText = JTextField("Specials")

    // gui components
    var display = JFrame()
    var button = JButton()
    var currVersion = " - alpha v5.14" // alpha version based off of the date that I am working on.

    // constructors
    constructor() {

        // load all the stages and weapon types into vectors
        File("brellas.txt").forEachLine { brellas.add(it) }
        File("chargers.txt").forEachLine { chargers.add(it) }
        File("dualies.txt").forEachLine { dualies.add(it) }
        File("rollers.txt").forEachLine { rollers.add(it) }
        File("shooters.txt").forEachLine { shooters.add(it) }
        File("sloshers.txt").forEachLine { sloshers.add(it) }
        File("splatlings.txt").forEachLine { splatlings.add(it) }


        // initialize JFrame
        display.setSize(1000, 500)
        display.title = "SplatStats" + currVersion
        display.layout = null
        display.isVisible = true


        var label1 = JLabel("Playing")
        label1.setBounds(10, 50, 50, 20)
        display.add(label1)
        label1.isVisible = true


        gameModes.isVisible = true
        gameModes.setBounds(70, 50, 120, 20)


        var label2 = JLabel("on")
        label2.setBounds(230, 50, 20, 20)
        display.add(label2)
        label2.isVisible = true

        stageDropDown.isVisible = true
        stageDropDown.setBounds(260, 50, 170, 20)

        weaponTypes.isVisible = true
        weaponTypes.setBounds(440, 50, 100, 20)
        weaponTypes.addActionListener( { changeGeneralWeaponDropDown() } )


        generalWeaponDropDown?.isVisible = true
        generalWeaponDropDown?.setBounds(550, 50, 180, 20)

        // kills text field
        killsText.isVisible = true
        killsText.setBounds(760, 50, 50, 20)


        // special deploy text field
        specialText.isVisible = true
        specialText.setBounds(820, 50, 50, 20)

        // initialize JButton
        button.isVisible = true
        button.setBounds(880, 50, 100, 20)
        button.text = "Enter"

        button.addActionListener(this) // this seems like I might need to make my own Button class with a defined ActionListener response in order to not mix up multiple different actionListeners.



        display.add(button)
        display.add(stageDropDown)
        display.add(gameModes)
        display.add(weaponTypes)
        display.add(generalWeaponDropDown)
        display.add(killsText)
        display.add(specialText)

        // calling the function to set the general drop down list from the start of the program.
        changeGeneralWeaponDropDown()

        // close the program when the window is closed.
        display.defaultCloseOperation = WindowConstants.EXIT_ON_CLOSE

    }

    // methods

    fun changeGeneralWeaponDropDown() {
        // this function will change the contents of the general weapon drop down list based on the selected item in the weaponTypes drop down.

        weaponTypes.selectedItem?.let {

            var curVect = when (weaponTypes.selectedItem) {
                "Brellas" -> brellas
                "Chargers" -> chargers
                "Dualies" -> dualies
                "Rollers" -> rollers
                "Shooters" -> shooters
                "Sloshers" -> sloshers
                "Splatlings" -> splatlings

                else -> shooters
            }

            // remove all items from the general drop down
            generalWeaponDropDown?.removeAllItems()

            // populate the general weapon drop down with the items in the vector.
            for (item in curVect) { generalWeaponDropDown?.addItem(item) }

        }

    }

    override fun actionPerformed(e: ActionEvent?) {

        // TODO: rewrite this function to use the Gson class to turn the data class into a json line and write it to the correct file.
        // try to parse and convert the killsText and specialText to see if the strings are integers. If not, dont write to the files.


        // only append the weapon to the file if the item is not null.
        // this let statement is the same as checking for if the item is null or not.
        generalWeaponDropDown?.selectedItem?.let {

            File("trash.txt").appendText("${generalWeaponDropDown?.selectedItem}\r\n")

        }


        // checking if there is an exception that is thrown in the parsing of the string that was given.
        try {
            var test = killsText.text.toInt()

            println("the string contains the number $test")

        } catch (exe: NumberFormatException) {

            // create a pop-up window with an error message.
            // the number you entered needs to be a whole number.
            println("the string DOES NOT contain an Int!")
        }


        //println("button pressed")
        println("weapon ${generalWeaponDropDown?.selectedItem} kills ${killsText.text} special deploy ${specialText.text}  ")

        // set the drop down item to a default value when the user presses the button.
        generalWeaponDropDown?.selectedItem = null
        //generalWeaponDropDown?.removeAllItems()

        // resetting the text fields of the objects for the next round of data entry.
        killsText.text = null
        specialText.text = null

    }


}