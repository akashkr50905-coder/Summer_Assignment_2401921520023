package live;

import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;

public class Test {
    public static void main(String[] args) {

        // a. Veena instance
        Veena v = new Veena();
        v.play();

        // b. Saxophone instance
        Saxophone sax = new Saxophone();
        sax.play();

        // c. Playable reference variable
        Playable p1 = new Veena();
        p1.play();

        Playable p2 = new Saxophone();
        p2.play();
    }
}