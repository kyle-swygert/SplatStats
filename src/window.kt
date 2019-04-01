package window

import java.util.*
import javax.swing.*
import java.io.File
import java.awt.event.*
import dropDownMenus.*

class Window : ActionListener {

    // fields and data members


    // vectors of strings for data
    private var stages = Vector<String>()
    private var brellas = Vector<String>()
    private var chargers = Vector<String>()
    private var dualies = Vector<String>()
    private var rollers = Vector<String>()
    private var shooters = Vector<String>()
    private var sloshers = Vector<String>()
    private var splatlings = Vector<String>()
    private var weaponTypes = Vector<String>()

    private var stageDropDown = DropDownList("stages.txt")

    // gui components
    var display = JFrame()
    var button = JButton()
    var shooterDropDown = JComboBox<String>(shooters)
    var currVersion = " - alpha v0.1"
    var menu = JMenuBar()

    // constructors
    constructor() {

        // load all the stages and weapon types into vectors
        File("stages.txt").forEachLine { stages.add(it) }
        File("brellas.txt").forEachLine { brellas.add(it) }
        File("chargers.txt").forEachLine { chargers.add(it) }
        File("dualies.txt").forEachLine { dualies.add(it) }
        File("rollers.txt").forEachLine { rollers.add(it) }
        File("shooters.txt").forEachLine { shooters.add(it) }
        File("sloshers.txt").forEachLine { sloshers.add(it) }
        File("splatlings.txt").forEachLine { splatlings.add(it) }

        // initalize the weaponTypes vector
        weaponTypes.add("Brellas")
        weaponTypes.add("Chargers")
        weaponTypes.add("Dualies")
        weaponTypes.add("Rollers")
        weaponTypes.add("Shooters")
        weaponTypes.add("Sloshers")
        weaponTypes.add("Splatlings")




        // initialize JFrame
        display.setSize(1000, 500)
        display.title = "SplatStats" + currVersion
        display.layout = null
        display.isVisible = true

        // initialize JButton
        button.isVisible = false

        button.setBounds(10, 10, 100, 20)
        button.text = "testing"

        //button.addActionListener(this) // this seems like I might need to make my own Button class with a defined ActionListener response in order to not mix up multiple different actionListeners.

        display.add(button)
        // initialize JComboBox

        shooterDropDown.isVisible = true
        shooterDropDown.setBounds(200, 200, 300, 20)

        shooterDropDown.addActionListener(this)

        stageDropDown.isVisible = true
        stageDropDown.setBounds(300, 300, 400, 30)


        menu.isVisible = true
        menu.setBounds(0, 0, 1000, 20)

        menu.add(JMenuItem("Data Input"))
        menu.add(JMenuItem("Stats"))
        menu.add(JMenuItem("Settings"))


        display.add(menu)

        display.add(stageDropDown)

        display.add(shooterDropDown)

    }

    // methods

    override fun actionPerformed(e: ActionEvent?) {
        //TODO("not implemented") //To change body of created functions use File | Settings | File Templates.



        //println("button pressed")
        println(shooterDropDown.selectedItem)
    }

    fun settingsButtonPressed(): Unit {
        // change the items for the settings screen.

        // if settings screen is already being displayed, don't change anything.

    }

    fun dataInputButtonPressed(): Unit {
        // change the items for the data input screen.

        // if data input screen is already being displayed, don't change anything.
    }




}