
# CustomAlertWrapper

CustomAlertWrapper is an Adobe AIR Native Extension (ANE) that allows developers to show customizable native alert dialogs in their AIR applications. It provides a simple way to present questions to users with options for "Yes" and "No," allowing for straightforward interaction.

## Features

- Display native alerts with customizable messages, titles, and button labels.
- Set a default button for user convenience.
- Easy integration into Adobe AIR applications.
- Handles status events from native code.

## Installation

1. Download the `CustomAlertWrapper.ane` file from this repository.
2. Add the ANE file to your Adobe AIR project:
   - In Adobe Animate, go to **File** > **AIR for iOS** (or **AIR for Android** / **AIR for Desktop**).
   - Include the `CustomAlertWrapper.ane` file in your project settings.

## Requirements

- Adobe AIR Desktop version 51.1
- Windows operating system

## Usage

To use the `CustomAlertWrapper`, follow these steps:

1. Import the class in your ActionScript file:

    ```actionscript
    import com.milad.extensions.CustomAlertWrapper;
    ```

2. Create an instance of the `CustomAlertWrapper`:

    ```actionscript
    var alertWrapper:CustomAlertWrapper = new CustomAlertWrapper();
    ```

3. Call the `showQuestion` method to display a question dialog:

    ```actionscript
    var message:String = "Do you want to continue?";
    var yesLabel:String = "Yes";
    var noLabel:String = "No";
    var title:String = "Confirmation";
    var yesDefault:Boolean = true; // Set "Yes" as the default button

    var result:uint = alertWrapper.showQuestion(message, yesLabel, noLabel, title, yesDefault);
    ```

4. Process the result:

    ```actionscript
    if (result == 1) {
        trace("User selected 'Yes'.");
    } else {
        trace("User selected 'No'.");
    }
    ```

## Example

Here’s a simple example of how to integrate `CustomAlertWrapper` in your AIR application:

```actionscript
package {
    import flash.display.Sprite;
    import flash.events.MouseEvent;
    import com.milad.extensions.CustomAlertWrapper;

    public class Main extends Sprite {
        private var alertWrapper: CustomAlertWrapper;

        public function Main() {
            alertWrapper = new CustomAlertWrapper();
            var button: Sprite = createButton("Show Question");
            button.addEventListener(MouseEvent.CLICK, showQuestion);
            addChild(button);
        }

        private function showQuestion(event: MouseEvent): void {
            var message:String = "Do you want to continue?";
            var yesLabel:String = "Yes";
            var noLabel:String = "No";
            var title:String = "Confirmation";
            var yesDefault:Boolean = true;

            var result:uint = alertWrapper.showQuestion(message, yesLabel, noLabel, title, yesDefault);

            if (result == 1) {
                trace("User selected 'Yes'.");
            } else {
                trace("User selected 'No'.");
            }
        }

        private function createButton(label:String):Sprite {
            var btn:Sprite = new Sprite();
            btn.graphics.beginFill(0x007ACC);
            btn.graphics.drawRect(0, 0, 150, 50);
            btn.graphics.endFill();

            var textField:TextField = new TextField();
            textField.text = label;
            textField.mouseEnabled = false;
            btn.addChild(textField);
            btn.buttonMode = true;
            btn.useHandCursor = true;

            return btn;
        }
    }
}
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any bugs or feature requests.

## Acknowledgments

- Thanks to the Adobe AIR community for their continuous support and contributions.

## Contact
For any inquiries or support, please contact [Milad](mailto:miladtaban@gmail.com.com).
