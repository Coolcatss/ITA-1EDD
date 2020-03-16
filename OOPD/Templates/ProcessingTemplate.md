# ProcessingTemplate

## Processing importen
Hier laat ik zien hoe je processing in Eclipse kan gebruiken.

<ol> 
	<li>Right-click op je project.</li>
	<li>Klik op Import...</li>
	<li>Klik op Next of Enter</li>
	<li>Zoek Processing.</li>
	<li>In het linker venster druk op het pijltje omlaag.</li>
	<li>Selecteer Core.</li>
	<li>Klik op Finish</li>
	<li>In je Hierarchy unfold core en right-click op Library</li>
	<li>Klik op Build path.</li>
</ol>
<p>
Nu je je path hebt gebuild kun je Processing gebruiken in Eclipse Wel moet je nog "import processing.core.PApplet;" aan het begin van je programma zetten.
</p>

## Template
<p>Hieronder staat wat start-code voor als je geen zin hebt om te typen.
Vergeet niet om in PApplet.main de package naam in te voeren.
</p>

```java

import processing.core.PApplet;

public class App extends PApplet {

	public static void main(String[] args) {
		PApplet.main("//packageName".App");
	}

	public void settings() {

	}
	
	public void setup() {


		}
	public void draw() {

		}
}
```
