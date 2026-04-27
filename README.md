# MY MELODY PLAYER PATHFINDER
---
it has all the normal essentials of XIAO RP2040 the 3 leds resistors and the keyswitches, the lights light up when the keys are pressed
however my design specifically focuses on the added buzzers, as a sequence of buttons is pressed, if it is a random sequence it will reflash the sequence of lights and make a TUNN sound, otherwise if its one of the passwords put in the code, it will play the corresponding melody, the melody could be played in a manner of approaches like the by melodyonallbuzzers function which makes all 3 play the melody, or the other ones that play it on only one buzzer, or the chords as well
this has a great potential if the time is taken to properly write down the notes of a song and its durations

I wanted to simply add buzzers at first but I thought of making some sort of music and stumbled upon the idea to make it so that it plays on its own if a sequence is entered

## IMAGE
---
### schematic and pcb
<img width="926" height="738" alt="image" src="https://github.com/user-attachments/assets/fd7587fd-c671-4ff1-af08-7fe8223a4fab" />
<img width="1199" height="702" alt="image" src="https://github.com/user-attachments/assets/832fa2b5-414e-421c-af84-65c1d1364f77" />

### case
<img width="698" height="640" alt="image" src="https://github.com/user-attachments/assets/fdce57d9-3c1f-4dfd-84b6-9c5e1d6ad546" />

### 3d view with componets
<img width="1073" height="758" alt="image" src="https://github.com/user-attachments/assets/e55f5028-5f4f-45ab-b294-89da5c8dcb1b" />


### I WILL BE PAYING FOR IT MYSELF
## BOM
---
| Parts | COST | LINK |
|-------|------|------|
| KEYSWITCH 10 peice | 7 USD | [Daraz](https://www.daraz.pk/products/mechanical-keyboard-switches-3-pin-rgb-hot-swappable-blue-red-brown-black-silent-tactile-switches-for-gaming-keyboard-70-million-clicks-durability-pc-gaming-keyboard-accessories-diy-keyboard-switches-set-i936558752-s3994103046.html) |
| Buzzers 10 peice | 1.58 USD | [AliExpress](https://ar.aliexpress.com/item/1005008165091345.html?spm=a2g0o.productlist.main.8.3c86xKOixKOitP&aem_p4p_detail=202604270416102094164706196300001174606&algo_pvid=e2f0ab90-6a1b-48cf-8a82-a7af61c8c830&algo_exp_id=e2f0ab90-6a1b-48cf-8a82-a7af61c8c830-7&pdp_ext_f=%7B"order"%3A"139"%2C"spu_best_type"%3A"price"%2C"eval"%3A"1"%2C"fromPage"%3A"search"%7D&pdp_npi=6%40dis%21USD%211.58%211.58%21%21%2110.75%2110.75%21%402140ec5d17772885701743231ef38d%2112000044055302230%21sea%21OM%216453760668%21X%211%210%21n_tag%3A-29911%3Bd%3A4b15dde3%3Bm03_new_user%3A-29895&curPageLogUid=FBDDN1ZaPHbf&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008165091345%7C_p_origin_prod%3A&search_p4p_id=202604270416102094164706196300001174606_2) |
| XIAO RP2040 | 6.31 USD | [AliExpress](https://ar.aliexpress.com/item/1005006593701624.html?spm=a2g0o.productlist.main.1.594e72a0k3wotb&algo_pvid=3994ba39-1c0d-4fbb-9548-68c0d8941582&algo_exp_id=3994ba39-1c0d-4fbb-9548-68c0d8941582-0&pdp_ext_f=%7B"order"%3A"447"%2C"eval"%3A"1"%2C"fromPage"%3A"search"%7D&pdp_npi=6%40dis%21USD%216.31%214.67%21%21%216.31%214.67%21%402140ec5d17772896468825754ef38f%2112000039072595754%21sea%21OM%216453760668%21X%211%210%21n_tag%3A-29911%3Bd%3A4b15dde3%3Bm03_new_user%3A-29895&curPageLogUid=k188lO9MGhtl&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006593701624%7C_p_origin_prod%3A) |
| LED 3 | --- | from my personal electronics kit, already had some |
| Resistors 3 |---| also from my own kit |
