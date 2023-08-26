/* Define lists for list of course for macros. Each of the following fields are described:
 * Argument 1: Course macro for define.
 * Argument 2: Star collection dance cutscenes
 * Each hex digit determines what dance cutscene to play for the stars in the course. The last digit is
 * unused. See determine_dance_cutscene() in camera.c for details.
 * Cutscene Digits:
 *      0: Lakitu flies away after the dance
 *      1: The camera rotates around mario
 *      2: The camera goes to a closeup of mario
 *      3: Bowser keys and the grand star
 *      4: Default, used for 100 coin stars, 8 red coin stars in bowser levels, and secret stars
 */
DEFINE_COURSE(COURSE_NONE, 0x44444440) // (0)  Course Hub (Castle Grounds)
DEFINE_COURSE(COURSE_BOB, 0x44444440) // (1)  Bob Omb Battlefield
DEFINE_COURSE(COURSE_WF, 0x44444440) // (2)  Whomp's Fortress
DEFINE_COURSE(COURSE_JRB, 0x44444440) // (3)  Jolly Rodger's Bay
DEFINE_COURSE(COURSE_CCM, 0x44444440) // (4)  Cool Cool Mountain
DEFINE_COURSE(COURSE_BBH, 0x44444440) // (5)  Big Boo's Haunt
DEFINE_COURSE(COURSE_HMC, 0x44444440) // (6)  Hazy Maze Cave
DEFINE_COURSE(COURSE_LLL, 0x44444440) // (7)  Lethal Lava Land
DEFINE_COURSE(COURSE_SSL, 0x44444440) // (8)  Shifting Sand Land
DEFINE_COURSE(COURSE_DDD, 0x44444440) // (9)  Dire Dire Docks
DEFINE_COURSE(COURSE_SL, 0x44444440) // (10) Snowman's Land
DEFINE_COURSE(COURSE_WDW, 0x44444440) // (11) Wet Dry World
DEFINE_COURSE(COURSE_TTM, 0x44444440) // (12) Tall Tall Mountain
DEFINE_COURSE(COURSE_THI, 0x44444440) // (13) Tiny Huge Island
DEFINE_COURSE(COURSE_TTC, 0x22222240) // (14) Tick Tock Clock
DEFINE_COURSE(COURSE_RR, 0x00000040) // (15) Rainbow Ride
DEFINE_COURSES_END()
DEFINE_BONUS_COURSE(COURSE_BITDW, 0x44444440) // (16) Bowser in the Dark World
DEFINE_BONUS_COURSE(COURSE_BITFS, 0x44444440) // (17) Bowser in the Fire Sea
DEFINE_BONUS_COURSE(COURSE_BITS, 0x44444440) // (18) Bowser in the Sky
DEFINE_BONUS_COURSE(COURSE_PSS, 0x24444440) // (19) Princess's Secret Slide
DEFINE_BONUS_COURSE(COURSE_COTMC, 0x44444440) // (20) Cavern of the Metal Cap
DEFINE_BONUS_COURSE(COURSE_TOTWC, 0x44444440) // (21) Tower of the Wing Cap
DEFINE_BONUS_COURSE(COURSE_VCUTM, 0x44444440) // (22) Vanish Cap Under the Moat
DEFINE_BONUS_COURSE(COURSE_WMOTR, 0x44444440) // (23) Winged Mario over the Rainbow
DEFINE_BONUS_COURSE(COURSE_SA, 0x24444440) // (24) Secret Aquarium
DEFINE_BONUS_COURSE(COURSE_CAKE_END, 0x44444440) // (25) The End (Cake Scene)
