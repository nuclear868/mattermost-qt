/**
 * @file EmojiMap.cpp
 * @brief Auto-generated file, containing emoji-name to emoji-string map
 * @author Lyubomir Filipov
 * @date Jul 28, 2022
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT; if not, see https://www.gnu.org/licenses/.
 */

#include "EmojiMap.h"

namespace Mattermost {

static const QString emojiStrings[] {
	"",		//(placeholder for not found emoji)
	"😀",	//grinning
	"😃",	//smiley
	"😄",	//smile
	"😁",	//grin
	"😆",	//laughing
	"😆",	//satisfied
	"😅",	//sweat_smile
	"🤣",	//rolling_on_the_floor_laughing
	"🤣",	//rofl
	"😂",	//joy
	"🙂",	//slightly_smiling_face
	"🙃",	//upside_down_face
	"😉",	//wink
	"😊",	//blush
	"😇",	//innocent
	"🥰",	//smiling_face_with_3_hearts
	"😍",	//heart_eyes
	"🤩",	//star-struck
	"🤩",	//grinning_face_with_star_eyes
	"😘",	//kissing_heart
	"😗",	//kissing
	"☺️",	//relaxed
	"😚",	//kissing_closed_eyes
	"😙",	//kissing_smiling_eyes
	"🥲",	//smiling_face_with_tear
	"😋",	//yum
	"😛",	//stuck_out_tongue
	"😜",	//stuck_out_tongue_winking_eye
	"🤪",	//zany_face
	"🤪",	//grinning_face_with_one_large_and_one_small_eye
	"😝",	//stuck_out_tongue_closed_eyes
	"🤑",	//money_mouth_face
	"🤗",	//hugging_face
	"🤗",	//hugs
	"🤭",	//face_with_hand_over_mouth
	"🤭",	//smiling_face_with_smiling_eyes_and_hand_covering_mouth
	"🤫",	//shushing_face
	"🤫",	//face_with_finger_covering_closed_lips
	"🤔",	//thinking_face
	"🤔",	//thinking
	"🤐",	//zipper_mouth_face
	"🤨",	//face_with_raised_eyebrow
	"🤨",	//face_with_one_eyebrow_raised
	"😐",	//neutral_face
	"😑",	//expressionless
	"😶",	//no_mouth
	"😏",	//smirk
	"😒",	//unamused
	"🙄",	//face_with_rolling_eyes
	"🙄",	//roll_eyes
	"😬",	//grimacing
	"🤥",	//lying_face
	"😌",	//relieved
	"😔",	//pensive
	"😪",	//sleepy
	"🤤",	//drooling_face
	"😴",	//sleeping
	"😷",	//mask
	"🤒",	//face_with_thermometer
	"🤕",	//face_with_head_bandage
	"🤢",	//nauseated_face
	"🤮",	//face_vomiting
	"🤮",	//face_with_open_mouth_vomiting
	"🤧",	//sneezing_face
	"🥵",	//hot_face
	"🥶",	//cold_face
	"🥴",	//woozy_face
	"😵",	//dizzy_face
	"🤯",	//exploding_head
	"🤯",	//shocked_face_with_exploding_head
	"🤠",	//face_with_cowboy_hat
	"🤠",	//cowboy_hat_face
	"🥳",	//partying_face
	"🥸",	//disguised_face
	"😎",	//sunglasses
	"🤓",	//nerd_face
	"🧐",	//face_with_monocle
	"😕",	//confused
	"😟",	//worried
	"🙁",	//slightly_frowning_face
	"☹️",	//white_frowning_face
	"☹️",	//frowning_face
	"😮",	//open_mouth
	"😯",	//hushed
	"😲",	//astonished
	"😳",	//flushed
	"🥺",	//pleading_face
	"😦",	//frowning
	"😧",	//anguished
	"😨",	//fearful
	"😰",	//cold_sweat
	"😥",	//disappointed_relieved
	"😢",	//cry
	"😭",	//sob
	"😱",	//scream
	"😖",	//confounded
	"😣",	//persevere
	"😞",	//disappointed
	"😓",	//sweat
	"😩",	//weary
	"😫",	//tired_face
	"🥱",	//yawning_face
	"😤",	//triumph
	"😡",	//rage
	"😡",	//pout
	"😠",	//angry
	"🤬",	//face_with_symbols_on_mouth
	"🤬",	//serious_face_with_symbols_covering_mouth
	"😈",	//smiling_imp
	"👿",	//imp
	"💀",	//skull
	"☠️",	//skull_and_crossbones
	"💩",	//hankey
	"💩",	//poop
	"💩",	//shit
	"🤡",	//clown_face
	"👹",	//japanese_ogre
	"👺",	//japanese_goblin
	"👻",	//ghost
	"👽",	//alien
	"👾",	//space_invader
	"🤖",	//robot_face
	"🤖",	//robot
	"😺",	//smiley_cat
	"😸",	//smile_cat
	"😹",	//joy_cat
	"😻",	//heart_eyes_cat
	"😼",	//smirk_cat
	"😽",	//kissing_cat
	"🙀",	//scream_cat
	"😿",	//crying_cat_face
	"😾",	//pouting_cat
	"🙈",	//see_no_evil
	"🙉",	//hear_no_evil
	"🙊",	//speak_no_evil
	"💋",	//kiss
	"💌",	//love_letter
	"💘",	//cupid
	"💝",	//gift_heart
	"💖",	//sparkling_heart
	"💗",	//heartpulse
	"💓",	//heartbeat
	"💞",	//revolving_hearts
	"💕",	//two_hearts
	"💟",	//heart_decoration
	"❣️",	//heavy_heart_exclamation_mark_ornament
	"❣️",	//heavy_heart_exclamation
	"💔",	//broken_heart
	"❤️",	//heart
	"🧡",	//orange_heart
	"💛",	//yellow_heart
	"💚",	//green_heart
	"💙",	//blue_heart
	"💜",	//purple_heart
	"🤎",	//brown_heart
	"🖤",	//black_heart
	"🤍",	//white_heart
	"💯",	//100
	"💢",	//anger
	"💥",	//boom
	"💥",	//collision
	"💫",	//dizzy
	"💦",	//sweat_drops
	"💨",	//dash
	"🕳️",	//hole
	"💣",	//bomb
	"💬",	//speech_balloon
	"👁️‍🗨️",	//eye-in-speech-bubble
	"🗨️",	//left_speech_bubble
	"🗯️",	//right_anger_bubble
	"💭",	//thought_balloon
	"💤",	//zzz
	"👋",	//wave
	"🤚",	//raised_back_of_hand
	"🖐️",	//raised_hand_with_fingers_splayed
	"✋",		//hand
	"✋",		//raised_hand
	"🖖",	//spock-hand
	"🖖",	//vulcan_salute
	"👌",	//ok_hand
	"🤌",	//pinched_fingers
	"🤏",	//pinching_hand
	"✌️",	//v
	"🤞",	//crossed_fingers
	"🤞",	//hand_with_index_and_middle_fingers_crossed
	"🤟",	//i_love_you_hand_sign
	"🤘",	//the_horns
	"🤘",	//sign_of_the_horns
	"🤘",	//metal
	"🤙",	//call_me_hand
	"👈",	//point_left
	"👉",	//point_right
	"👆",	//point_up_2
	"🖕",	//middle_finger
	"🖕",	//reversed_hand_with_middle_finger_extended
	"🖕",	//fu
	"👇",	//point_down
	"☝️",	//point_up
	"👍",	//+1
	"👍",	//thumbsup
	"👎",	//-1
	"👎",	//thumbsdown
	"✊",		//fist
	"✊",		//fist_raised
	"👊",	//facepunch
	"👊",	//punch
	"👊",	//fist_oncoming
	"🤛",	//left-facing_fist
	"🤛",	//fist_left
	"🤜",	//right-facing_fist
	"🤜",	//fist_right
	"👏",	//clap
	"🙌",	//raised_hands
	"👐",	//open_hands
	"🤲",	//palms_up_together
	"🤝",	//handshake
	"🙏",	//pray
	"✍️",	//writing_hand
	"💅",	//nail_care
	"🤳",	//selfie
	"💪",	//muscle
	"🦾",	//mechanical_arm
	"🦿",	//mechanical_leg
	"🦵",	//leg
	"🦶",	//foot
	"👂",	//ear
	"🦻",	//ear_with_hearing_aid
	"👃",	//nose
	"🧠",	//brain
	"🫀",	//anatomical_heart
	"🫁",	//lungs
	"🦷",	//tooth
	"🦴",	//bone
	"👀",	//eyes
	"👁️",	//eye
	"👅",	//tongue
	"👄",	//lips
	"👶",	//baby
	"🧒",	//child
	"👦",	//boy
	"👧",	//girl
	"🧑",	//adult
	"👱",	//person_with_blond_hair
	"👨",	//man
	"🧔",	//bearded_person
	"👨‍🦰",	//red_haired_man
	"👨‍🦱",	//curly_haired_man
	"👨‍🦳",	//white_haired_man
	"👨‍🦲",	//bald_man
	"👩",	//woman
	"👩‍🦰",	//red_haired_woman
	"🧑‍🦰",	//red_haired_person
	"👩‍🦱",	//curly_haired_woman
	"🧑‍🦱",	//curly_haired_person
	"👩‍🦳",	//white_haired_woman
	"🧑‍🦳",	//white_haired_person
	"👩‍🦲",	//bald_woman
	"🧑‍🦲",	//bald_person
	"👱‍♀️",	//blond-haired-woman
	"👱‍♀️",	//blonde_woman
	"👱‍♂️",	//blond-haired-man
	"👱‍♂️",	//blonde_man
	"🧓",	//older_adult
	"👴",	//older_man
	"👵",	//older_woman
	"🙍",	//person_frowning
	"🙍‍♂️",	//man-frowning
	"🙍‍♂️",	//frowning_man
	"🙍‍♀️",	//woman-frowning
	"🙍‍♀️",	//frowning_woman
	"🙎",	//person_with_pouting_face
	"🙎‍♂️",	//man-pouting
	"🙎‍♂️",	//pouting_man
	"🙎‍♀️",	//woman-pouting
	"🙎‍♀️",	//pouting_woman
	"🙅",	//no_good
	"🙅‍♂️",	//man-gesturing-no
	"🙅‍♂️",	//ng_man
	"🙅‍♂️",	//no_good_man
	"🙅‍♀️",	//woman-gesturing-no
	"🙅‍♀️",	//no_good_woman
	"🙅‍♀️",	//ng_woman
	"🙆",	//ok_woman
	"🙆‍♂️",	//man-gesturing-ok
	"🙆‍♂️",	//ok_man
	"🙆‍♀️",	//woman-gesturing-ok
	"💁",	//information_desk_person
	"💁‍♂️",	//man-tipping-hand
	"💁‍♂️",	//tipping_hand_man
	"💁‍♀️",	//woman-tipping-hand
	"💁‍♀️",	//tipping_hand_woman
	"🙋",	//raising_hand
	"🙋‍♂️",	//man-raising-hand
	"🙋‍♂️",	//raising_hand_man
	"🙋‍♀️",	//woman-raising-hand
	"🙋‍♀️",	//raising_hand_woman
	"🧏",	//deaf_person
	"🧏‍♂️",	//deaf_man
	"🧏‍♀️",	//deaf_woman
	"🙇",	//bow
	"🙇‍♂️",	//man-bowing
	"🙇‍♂️",	//bowing_man
	"🙇‍♀️",	//woman-bowing
	"🙇‍♀️",	//bowing_woman
	"🤦",	//face_palm
	"🤦‍♂️",	//man-facepalming
	"🤦‍♂️",	//man_facepalming
	"🤦‍♀️",	//woman-facepalming
	"🤦‍♀️",	//woman_facepalming
	"🤷",	//shrug
	"🤷‍♂️",	//man-shrugging
	"🤷‍♂️",	//man_shrugging
	"🤷‍♀️",	//woman-shrugging
	"🤷‍♀️",	//woman_shrugging
	"🧑‍⚕️",	//health_worker
	"🧑‍⚕️",	//doctor
	"👨‍⚕️",	//male-doctor
	"👨‍⚕️",	//man_health_worker
	"👩‍⚕️",	//female-doctor
	"👩‍⚕️",	//woman_health_worker
	"🧑‍🎓",	//student
	"👨‍🎓",	//male-student
	"👨‍🎓",	//man_student
	"👩‍🎓",	//female-student
	"👩‍🎓",	//woman_student
	"🧑‍🏫",	//teacher
	"👨‍🏫",	//male-teacher
	"👨‍🏫",	//man_teacher
	"👩‍🏫",	//female-teacher
	"👩‍🏫",	//woman_teacher
	"🧑‍⚖️",	//judge
	"👨‍⚖️",	//male-judge
	"👨‍⚖️",	//man_judge
	"👩‍⚖️",	//female-judge
	"👩‍⚖️",	//woman_judge
	"🧑‍🌾",	//farmer
	"👨‍🌾",	//male-farmer
	"👨‍🌾",	//man_farmer
	"👩‍🌾",	//female-farmer
	"👩‍🌾",	//woman_farmer
	"🧑‍🍳",	//cook
	"👨‍🍳",	//male-cook
	"👨‍🍳",	//man_cook
	"👩‍🍳",	//female-cook
	"👩‍🍳",	//woman_cook
	"🧑‍🔧",	//mechanic
	"👨‍🔧",	//male-mechanic
	"👨‍🔧",	//man_mechanic
	"👩‍🔧",	//female-mechanic
	"👩‍🔧",	//woman_mechanic
	"🧑‍🏭",	//factory_worker
	"👨‍🏭",	//male-factory-worker
	"👨‍🏭",	//man_factory_worker
	"👩‍🏭",	//female-factory-worker
	"👩‍🏭",	//woman_factory_worker
	"🧑‍💼",	//office_worker
	"👨‍💼",	//male-office-worker
	"👨‍💼",	//man_office_worker
	"👩‍💼",	//female-office-worker
	"👩‍💼",	//woman_office_worker
	"🧑‍🔬",	//scientist
	"👨‍🔬",	//male-scientist
	"👨‍🔬",	//man_scientist
	"👩‍🔬",	//female-scientist
	"👩‍🔬",	//woman_scientist
	"🧑‍💻",	//technologist
	"👨‍💻",	//male-technologist
	"👨‍💻",	//man_technologist
	"👩‍💻",	//female-technologist
	"👩‍💻",	//woman_technologist
	"🧑‍🎤",	//singer
	"👨‍🎤",	//male-singer
	"👨‍🎤",	//man_singer
	"👩‍🎤",	//female-singer
	"👩‍🎤",	//woman_singer
	"🧑‍🎨",	//artist
	"👨‍🎨",	//male-artist
	"👨‍🎨",	//man_artist
	"👩‍🎨",	//female-artist
	"👩‍🎨",	//woman_artist
	"🧑‍✈️",	//pilot
	"👨‍✈️",	//male-pilot
	"👨‍✈️",	//man_pilot
	"👩‍✈️",	//female-pilot
	"👩‍✈️",	//woman_pilot
	"🧑‍🚀",	//astronaut
	"👨‍🚀",	//male-astronaut
	"👨‍🚀",	//man_astronaut
	"👩‍🚀",	//female-astronaut
	"👩‍🚀",	//woman_astronaut
	"🧑‍🚒",	//firefighter
	"👨‍🚒",	//male-firefighter
	"👨‍🚒",	//man_firefighter
	"👩‍🚒",	//female-firefighter
	"👩‍🚒",	//woman_firefighter
	"👮",	//cop
	"👮‍♂️",	//male-police-officer
	"👮‍♂️",	//policeman
	"👮‍♀️",	//female-police-officer
	"👮‍♀️",	//policewoman
	"🕵️",	//sleuth_or_spy
	"🕵️",	//detective
	"🕵️‍♂️",	//male-detective
	"🕵️‍♂️",	//male_detective
	"🕵️‍♀️",	//female-detective
	"🕵️‍♀️",	//female_detective
	"💂",	//guardsman
	"💂‍♂️",	//male-guard
	"💂‍♀️",	//female-guard
	"💂‍♀️",	//guardswoman
	"🥷",	//ninja
	"👷",	//construction_worker
	"👷‍♂️",	//male-construction-worker
	"👷‍♂️",	//construction_worker_man
	"👷‍♀️",	//female-construction-worker
	"👷‍♀️",	//construction_worker_woman
	"🤴",	//prince
	"👸",	//princess
	"👳",	//man_with_turban
	"👳‍♂️",	//man-wearing-turban
	"👳‍♀️",	//woman-wearing-turban
	"👳‍♀️",	//woman_with_turban
	"👲",	//man_with_gua_pi_mao
	"🧕",	//person_with_headscarf
	"🤵",	//person_in_tuxedo
	"🤵‍♂️",	//man_in_tuxedo
	"🤵‍♀️",	//woman_in_tuxedo
	"👰",	//bride_with_veil
	"👰‍♂️",	//man_with_veil
	"👰‍♀️",	//woman_with_veil
	"🤰",	//pregnant_woman
	"🤱",	//breast-feeding
	"👩‍🍼",	//woman_feeding_baby
	"👨‍🍼",	//man_feeding_baby
	"🧑‍🍼",	//person_feeding_baby
	"👼",	//angel
	"🎅",	//santa
	"🤶",	//mrs_claus
	"🤶",	//mother_christmas
	"🧑‍🎄",	//mx_claus
	"🦸",	//superhero
	"🦸‍♂️",	//male_superhero
	"🦸‍♀️",	//female_superhero
	"🦹",	//supervillain
	"🦹‍♂️",	//male_supervillain
	"🦹‍♀️",	//female_supervillain
	"🧙",	//mage
	"🧙‍♂️",	//male_mage
	"🧙‍♀️",	//female_mage
	"🧚",	//fairy
	"🧚‍♂️",	//male_fairy
	"🧚‍♀️",	//female_fairy
	"🧛",	//vampire
	"🧛‍♂️",	//male_vampire
	"🧛‍♀️",	//female_vampire
	"🧜",	//merperson
	"🧜‍♂️",	//merman
	"🧜‍♀️",	//mermaid
	"🧝",	//elf
	"🧝‍♂️",	//male_elf
	"🧝‍♀️",	//female_elf
	"🧞",	//genie
	"🧞‍♂️",	//male_genie
	"🧞‍♀️",	//female_genie
	"🧟",	//zombie
	"🧟‍♂️",	//male_zombie
	"🧟‍♀️",	//female_zombie
	"💆",	//massage
	"💆‍♂️",	//man-getting-massage
	"💆‍♂️",	//massage_man
	"💆‍♀️",	//woman-getting-massage
	"💆‍♀️",	//massage_woman
	"💇",	//haircut
	"💇‍♂️",	//man-getting-haircut
	"💇‍♂️",	//haircut_man
	"💇‍♀️",	//woman-getting-haircut
	"💇‍♀️",	//haircut_woman
	"🚶",	//walking
	"🚶‍♂️",	//man-walking
	"🚶‍♂️",	//walking_man
	"🚶‍♀️",	//woman-walking
	"🚶‍♀️",	//walking_woman
	"🧍",	//standing_person
	"🧍‍♂️",	//man_standing
	"🧍‍♀️",	//woman_standing
	"🧎",	//kneeling_person
	"🧎‍♂️",	//man_kneeling
	"🧎‍♀️",	//woman_kneeling
	"🧑‍🦯",	//person_with_probing_cane
	"👨‍🦯",	//man_with_probing_cane
	"👩‍🦯",	//woman_with_probing_cane
	"🧑‍🦼",	//person_in_motorized_wheelchair
	"👨‍🦼",	//man_in_motorized_wheelchair
	"👩‍🦼",	//woman_in_motorized_wheelchair
	"🧑‍🦽",	//person_in_manual_wheelchair
	"👨‍🦽",	//man_in_manual_wheelchair
	"👩‍🦽",	//woman_in_manual_wheelchair
	"🏃",	//runner
	"🏃",	//running
	"🏃‍♂️",	//man-running
	"🏃‍♂️",	//running_man
	"🏃‍♀️",	//woman-running
	"🏃‍♀️",	//running_woman
	"💃",	//dancer
	"🕺",	//man_dancing
	"🕴️",	//man_in_business_suit_levitating
	"🕴️",	//business_suit_levitating
	"👯",	//dancers
	"👯‍♂️",	//man-with-bunny-ears-partying
	"👯‍♂️",	//dancing_men
	"👯‍♀️",	//woman-with-bunny-ears-partying
	"👯‍♀️",	//dancing_women
	"🧖",	//person_in_steamy_room
	"🧖‍♂️",	//man_in_steamy_room
	"🧖‍♀️",	//woman_in_steamy_room
	"🧗",	//person_climbing
	"🧗‍♂️",	//man_climbing
	"🧗‍♀️",	//woman_climbing
	"🤺",	//fencer
	"🤺",	//person_fencing
	"🏇",	//horse_racing
	"⛷️",	//skier
	"🏂",	//snowboarder
	"🏌️",	//golfer
	"🏌️‍♂️",	//man-golfing
	"🏌️‍♂️",	//golfing_man
	"🏌️‍♀️",	//woman-golfing
	"🏌️‍♀️",	//golfing_woman
	"🏄",	//surfer
	"🏄‍♂️",	//man-surfing
	"🏄‍♂️",	//surfing_man
	"🏄‍♀️",	//woman-surfing
	"🏄‍♀️",	//surfing_woman
	"🚣",	//rowboat
	"🚣‍♂️",	//man-rowing-boat
	"🚣‍♂️",	//rowing_man
	"🚣‍♀️",	//woman-rowing-boat
	"🚣‍♀️",	//rowing_woman
	"🏊",	//swimmer
	"🏊‍♂️",	//man-swimming
	"🏊‍♂️",	//swimming_man
	"🏊‍♀️",	//woman-swimming
	"🏊‍♀️",	//swimming_woman
	"⛹️",	//person_with_ball
	"⛹️‍♂️",	//man-bouncing-ball
	"⛹️‍♂️",	//basketball_man
	"⛹️‍♀️",	//woman-bouncing-ball
	"⛹️‍♀️",	//basketball_woman
	"🏋️",	//weight_lifter
	"🏋️‍♂️",	//man-lifting-weights
	"🏋️‍♂️",	//weight_lifting_man
	"🏋️‍♀️",	//woman-lifting-weights
	"🏋️‍♀️",	//weight_lifting_woman
	"🚴",	//bicyclist
	"🚴‍♂️",	//man-biking
	"🚴‍♂️",	//biking_man
	"🚴‍♀️",	//woman-biking
	"🚴‍♀️",	//biking_woman
	"🚵",	//mountain_bicyclist
	"🚵‍♂️",	//man-mountain-biking
	"🚵‍♂️",	//mountain_biking_man
	"🚵‍♀️",	//woman-mountain-biking
	"🚵‍♀️",	//mountain_biking_woman
	"🤸",	//person_doing_cartwheel
	"🤸‍♂️",	//man-cartwheeling
	"🤸‍♂️",	//man_cartwheeling
	"🤸‍♀️",	//woman-cartwheeling
	"🤸‍♀️",	//woman_cartwheeling
	"🤼",	//wrestlers
	"🤼‍♂️",	//man-wrestling
	"🤼‍♂️",	//men_wrestling
	"🤼‍♀️",	//woman-wrestling
	"🤼‍♀️",	//women_wrestling
	"🤽",	//water_polo
	"🤽‍♂️",	//man-playing-water-polo
	"🤽‍♂️",	//man_playing_water_polo
	"🤽‍♀️",	//woman-playing-water-polo
	"🤽‍♀️",	//woman_playing_water_polo
	"🤾",	//handball
	"🤾‍♂️",	//man-playing-handball
	"🤾‍♂️",	//man_playing_handball
	"🤾‍♀️",	//woman-playing-handball
	"🤾‍♀️",	//woman_playing_handball
	"🤹",	//juggling
	"🤹‍♂️",	//man-juggling
	"🤹‍♂️",	//man_juggling
	"🤹‍♀️",	//woman-juggling
	"🤹‍♀️",	//woman_juggling
	"🧘",	//person_in_lotus_position
	"🧘‍♂️",	//man_in_lotus_position
	"🧘‍♀️",	//woman_in_lotus_position
	"🛀",	//bath
	"🛌",	//sleeping_accommodation
	"🛌",	//sleeping_bed
	"🧑‍🤝‍🧑",	//people_holding_hands
	"👭",	//two_women_holding_hands
	"👭",	//women_holding_hands
	"👫",	//man_and_woman_holding_hands
	"👫",	//woman_and_man_holding_hands
	"👫",	//couple
	"👬",	//two_men_holding_hands
	"👬",	//men_holding_hands
	"💏",	//couplekiss
	"👩‍❤️‍💋‍👨",	//woman-kiss-man
	"👩‍❤️‍💋‍👨",	//couplekiss_man_woman
	"👨‍❤️‍💋‍👨",	//man-kiss-man
	"👨‍❤️‍💋‍👨",	//couplekiss_man_man
	"👩‍❤️‍💋‍👩",	//woman-kiss-woman
	"👩‍❤️‍💋‍👩",	//couplekiss_woman_woman
	"💑",	//couple_with_heart
	"👩‍❤️‍👨",	//woman-heart-man
	"👩‍❤️‍👨",	//couple_with_heart_woman_man
	"👨‍❤️‍👨",	//man-heart-man
	"👨‍❤️‍👨",	//couple_with_heart_man_man
	"👩‍❤️‍👩",	//woman-heart-woman
	"👩‍❤️‍👩",	//couple_with_heart_woman_woman
	"👪",	//family
	"👨‍👩‍👦",	//man-woman-boy
	"👨‍👩‍👦",	//family_man_woman_boy
	"👨‍👩‍👧",	//man-woman-girl
	"👨‍👩‍👧",	//family_man_woman_girl
	"👨‍👩‍👧‍👦",	//man-woman-girl-boy
	"👨‍👩‍👧‍👦",	//family_man_woman_girl_boy
	"👨‍👩‍👦‍👦",	//man-woman-boy-boy
	"👨‍👩‍👦‍👦",	//family_man_woman_boy_boy
	"👨‍👩‍👧‍👧",	//man-woman-girl-girl
	"👨‍👩‍👧‍👧",	//family_man_woman_girl_girl
	"👨‍👨‍👦",	//man-man-boy
	"👨‍👨‍👦",	//family_man_man_boy
	"👨‍👨‍👧",	//man-man-girl
	"👨‍👨‍👧",	//family_man_man_girl
	"👨‍👨‍👧‍👦",	//man-man-girl-boy
	"👨‍👨‍👧‍👦",	//family_man_man_girl_boy
	"👨‍👨‍👦‍👦",	//man-man-boy-boy
	"👨‍👨‍👦‍👦",	//family_man_man_boy_boy
	"👨‍👨‍👧‍👧",	//man-man-girl-girl
	"👨‍👨‍👧‍👧",	//family_man_man_girl_girl
	"👩‍👩‍👦",	//woman-woman-boy
	"👩‍👩‍👦",	//family_woman_woman_boy
	"👩‍👩‍👧",	//woman-woman-girl
	"👩‍👩‍👧",	//family_woman_woman_girl
	"👩‍👩‍👧‍👦",	//woman-woman-girl-boy
	"👩‍👩‍👧‍👦",	//family_woman_woman_girl_boy
	"👩‍👩‍👦‍👦",	//woman-woman-boy-boy
	"👩‍👩‍👦‍👦",	//family_woman_woman_boy_boy
	"👩‍👩‍👧‍👧",	//woman-woman-girl-girl
	"👩‍👩‍👧‍👧",	//family_woman_woman_girl_girl
	"👨‍👦",	//man-boy
	"👨‍👦",	//family_man_boy
	"👨‍👦‍👦",	//man-boy-boy
	"👨‍👦‍👦",	//family_man_boy_boy
	"👨‍👧",	//man-girl
	"👨‍👧",	//family_man_girl
	"👨‍👧‍👦",	//man-girl-boy
	"👨‍👧‍👦",	//family_man_girl_boy
	"👨‍👧‍👧",	//man-girl-girl
	"👨‍👧‍👧",	//family_man_girl_girl
	"👩‍👦",	//woman-boy
	"👩‍👦",	//family_woman_boy
	"👩‍👦‍👦",	//woman-boy-boy
	"👩‍👦‍👦",	//family_woman_boy_boy
	"👩‍👧",	//woman-girl
	"👩‍👧",	//family_woman_girl
	"👩‍👧‍👦",	//woman-girl-boy
	"👩‍👧‍👦",	//family_woman_girl_boy
	"👩‍👧‍👧",	//woman-girl-girl
	"👩‍👧‍👧",	//family_woman_girl_girl
	"🗣️",	//speaking_head_in_silhouette
	"🗣️",	//speaking_head
	"👤",	//bust_in_silhouette
	"👥",	//busts_in_silhouette
	"🫂",	//people_hugging
	"👣",	//footprints
	"🏻",	//skin-tone-2
	"🏼",	//skin-tone-3
	"🏽",	//skin-tone-4
	"🏾",	//skin-tone-5
	"🏿",	//skin-tone-6
	"🐵",	//monkey_face
	"🐒",	//monkey
	"🦍",	//gorilla
	"🦧",	//orangutan
	"🐶",	//dog
	"🐕",	//dog2
	"🦮",	//guide_dog
	"🐕‍🦺",	//service_dog
	"🐩",	//poodle
	"🐺",	//wolf
	"🦊",	//fox_face
	"🦝",	//raccoon
	"🐱",	//cat
	"🐈",	//cat2
	"🐈‍⬛",	//black_cat
	"🦁",	//lion_face
	"🦁",	//lion
	"🐯",	//tiger
	"🐅",	//tiger2
	"🐆",	//leopard
	"🐴",	//horse
	"🐎",	//racehorse
	"🦄",	//unicorn_face
	"🦄",	//unicorn
	"🦓",	//zebra_face
	"🦌",	//deer
	"🦬",	//bison
	"🐮",	//cow
	"🐂",	//ox
	"🐃",	//water_buffalo
	"🐄",	//cow2
	"🐷",	//pig
	"🐖",	//pig2
	"🐗",	//boar
	"🐽",	//pig_nose
	"🐏",	//ram
	"🐑",	//sheep
	"🐐",	//goat
	"🐪",	//dromedary_camel
	"🐫",	//camel
	"🦙",	//llama
	"🦒",	//giraffe_face
	"🐘",	//elephant
	"🦣",	//mammoth
	"🦏",	//rhinoceros
	"🦛",	//hippopotamus
	"🐭",	//mouse
	"🐁",	//mouse2
	"🐀",	//rat
	"🐹",	//hamster
	"🐰",	//rabbit
	"🐇",	//rabbit2
	"🐿️",	//chipmunk
	"🦫",	//beaver
	"🦔",	//hedgehog
	"🦇",	//bat
	"🐻",	//bear
	"🐻‍❄️",	//polar_bear
	"🐨",	//koala
	"🐼",	//panda_face
	"🦥",	//sloth
	"🦦",	//otter
	"🦨",	//skunk
	"🦘",	//kangaroo
	"🦡",	//badger
	"🐾",	//feet
	"🐾",	//paw_prints
	"🦃",	//turkey
	"🐔",	//chicken
	"🐓",	//rooster
	"🐣",	//hatching_chick
	"🐤",	//baby_chick
	"🐥",	//hatched_chick
	"🐦",	//bird
	"🐧",	//penguin
	"🕊️",	//dove_of_peace
	"🕊️",	//dove
	"🦅",	//eagle
	"🦆",	//duck
	"🦢",	//swan
	"🦉",	//owl
	"🦤",	//dodo
	"🪶",	//feather
	"🦩",	//flamingo
	"🦚",	//peacock
	"🦜",	//parrot
	"🐸",	//frog
	"🐊",	//crocodile
	"🐢",	//turtle
	"🦎",	//lizard
	"🐍",	//snake
	"🐲",	//dragon_face
	"🐉",	//dragon
	"🦕",	//sauropod
	"🦖",	//t-rex
	"🐳",	//whale
	"🐋",	//whale2
	"🐬",	//dolphin
	"🐬",	//flipper
	"🦭",	//seal
	"🐟",	//fish
	"🐠",	//tropical_fish
	"🐡",	//blowfish
	"🦈",	//shark
	"🐙",	//octopus
	"🐚",	//shell
	"🐌",	//snail
	"🦋",	//butterfly
	"🐛",	//bug
	"🐜",	//ant
	"🐝",	//bee
	"🐝",	//honeybee
	"🪲",	//beetle
	"🐞",	//ladybug
	"🐞",	//lady_beetle
	"🦗",	//cricket
	"🪳",	//cockroach
	"🕷️",	//spider
	"🕸️",	//spider_web
	"🦂",	//scorpion
	"🦟",	//mosquito
	"🪰",	//fly
	"🪱",	//worm
	"🦠",	//microbe
	"💐",	//bouquet
	"🌸",	//cherry_blossom
	"💮",	//white_flower
	"🏵️",	//rosette
	"🌹",	//rose
	"🥀",	//wilted_flower
	"🌺",	//hibiscus
	"🌻",	//sunflower
	"🌼",	//blossom
	"🌷",	//tulip
	"🌱",	//seedling
	"🪴",	//potted_plant
	"🌲",	//evergreen_tree
	"🌳",	//deciduous_tree
	"🌴",	//palm_tree
	"🌵",	//cactus
	"🌾",	//ear_of_rice
	"🌿",	//herb
	"☘️",	//shamrock
	"🍀",	//four_leaf_clover
	"🍁",	//maple_leaf
	"🍂",	//fallen_leaf
	"🍃",	//leaves
	"🍇",	//grapes
	"🍈",	//melon
	"🍉",	//watermelon
	"🍊",	//tangerine
	"🍊",	//mandarin
	"🍊",	//orange
	"🍋",	//lemon
	"🍌",	//banana
	"🍍",	//pineapple
	"🥭",	//mango
	"🍎",	//apple
	"🍏",	//green_apple
	"🍐",	//pear
	"🍑",	//peach
	"🍒",	//cherries
	"🍓",	//strawberry
	"🫐",	//blueberries
	"🥝",	//kiwifruit
	"🥝",	//kiwi_fruit
	"🍅",	//tomato
	"🫒",	//olive
	"🥥",	//coconut
	"🥑",	//avocado
	"🍆",	//eggplant
	"🥔",	//potato
	"🥕",	//carrot
	"🌽",	//corn
	"🌶️",	//hot_pepper
	"🫑",	//bell_pepper
	"🥒",	//cucumber
	"🥬",	//leafy_green
	"🥦",	//broccoli
	"🧄",	//garlic
	"🧅",	//onion
	"🍄",	//mushroom
	"🥜",	//peanuts
	"🌰",	//chestnut
	"🍞",	//bread
	"🥐",	//croissant
	"🥖",	//baguette_bread
	"🫓",	//flatbread
	"🥨",	//pretzel
	"🥯",	//bagel
	"🥞",	//pancakes
	"🧇",	//waffle
	"🧀",	//cheese_wedge
	"🧀",	//cheese
	"🍖",	//meat_on_bone
	"🍗",	//poultry_leg
	"🥩",	//cut_of_meat
	"🥓",	//bacon
	"🍔",	//hamburger
	"🍟",	//fries
	"🍕",	//pizza
	"🌭",	//hotdog
	"🥪",	//sandwich
	"🌮",	//taco
	"🌯",	//burrito
	"🫔",	//tamale
	"🥙",	//stuffed_flatbread
	"🧆",	//falafel
	"🥚",	//egg
	"🍳",	//fried_egg
	"🍳",	//cooking
	"🥘",	//shallow_pan_of_food
	"🍲",	//stew
	"🫕",	//fondue
	"🥣",	//bowl_with_spoon
	"🥗",	//green_salad
	"🍿",	//popcorn
	"🧈",	//butter
	"🧂",	//salt
	"🥫",	//canned_food
	"🍱",	//bento
	"🍘",	//rice_cracker
	"🍙",	//rice_ball
	"🍚",	//rice
	"🍛",	//curry
	"🍜",	//ramen
	"🍝",	//spaghetti
	"🍠",	//sweet_potato
	"🍢",	//oden
	"🍣",	//sushi
	"🍤",	//fried_shrimp
	"🍥",	//fish_cake
	"🥮",	//moon_cake
	"🍡",	//dango
	"🥟",	//dumpling
	"🥠",	//fortune_cookie
	"🥡",	//takeout_box
	"🦀",	//crab
	"🦞",	//lobster
	"🦐",	//shrimp
	"🦑",	//squid
	"🦪",	//oyster
	"🍦",	//icecream
	"🍧",	//shaved_ice
	"🍨",	//ice_cream
	"🍩",	//doughnut
	"🍪",	//cookie
	"🎂",	//birthday
	"🍰",	//cake
	"🧁",	//cupcake
	"🥧",	//pie
	"🍫",	//chocolate_bar
	"🍬",	//candy
	"🍭",	//lollipop
	"🍮",	//custard
	"🍯",	//honey_pot
	"🍼",	//baby_bottle
	"🥛",	//glass_of_milk
	"🥛",	//milk_glass
	"☕",		//coffee
	"🫖",	//teapot
	"🍵",	//tea
	"🍶",	//sake
	"🍾",	//champagne
	"🍷",	//wine_glass
	"🍸",	//cocktail
	"🍹",	//tropical_drink
	"🍺",	//beer
	"🍻",	//beers
	"🥂",	//clinking_glasses
	"🥃",	//tumbler_glass
	"🥤",	//cup_with_straw
	"🧋",	//bubble_tea
	"🧃",	//beverage_box
	"🧉",	//mate_drink
	"🧊",	//ice_cube
	"🥢",	//chopsticks
	"🍽️",	//knife_fork_plate
	"🍽️",	//plate_with_cutlery
	"🍴",	//fork_and_knife
	"🥄",	//spoon
	"🔪",	//hocho
	"🔪",	//knife
	"🏺",	//amphora
	"🌍",	//earth_africa
	"🌎",	//earth_americas
	"🌏",	//earth_asia
	"🌐",	//globe_with_meridians
	"🗺️",	//world_map
	"🗾",	//japan
	"🧭",	//compass
	"🏔️",	//snow_capped_mountain
	"🏔️",	//mountain_snow
	"⛰️",	//mountain
	"🌋",	//volcano
	"🗻",	//mount_fuji
	"🏕️",	//camping
	"🏖️",	//beach_with_umbrella
	"🏖️",	//beach_umbrella
	"🏜️",	//desert
	"🏝️",	//desert_island
	"🏞️",	//national_park
	"🏟️",	//stadium
	"🏛️",	//classical_building
	"🏗️",	//building_construction
	"🧱",	//bricks
	"🪨",	//rock
	"🪵",	//wood
	"🛖",	//hut
	"🏘️",	//house_buildings
	"🏘️",	//houses
	"🏚️",	//derelict_house_building
	"🏚️",	//derelict_house
	"🏠",	//house
	"🏡",	//house_with_garden
	"🏢",	//office
	"🏣",	//post_office
	"🏤",	//european_post_office
	"🏥",	//hospital
	"🏦",	//bank
	"🏨",	//hotel
	"🏩",	//love_hotel
	"🏪",	//convenience_store
	"🏫",	//school
	"🏬",	//department_store
	"🏭",	//factory
	"🏯",	//japanese_castle
	"🏰",	//european_castle
	"💒",	//wedding
	"🗼",	//tokyo_tower
	"🗽",	//statue_of_liberty
	"⛪",		//church
	"🕌",	//mosque
	"🛕",	//hindu_temple
	"🕍",	//synagogue
	"⛩️",	//shinto_shrine
	"🕋",	//kaaba
	"⛲",		//fountain
	"⛺",		//tent
	"🌁",	//foggy
	"🌃",	//night_with_stars
	"🏙️",	//cityscape
	"🌄",	//sunrise_over_mountains
	"🌅",	//sunrise
	"🌆",	//city_sunset
	"🌇",	//city_sunrise
	"🌉",	//bridge_at_night
	"♨️",	//hotsprings
	"🎠",	//carousel_horse
	"🎡",	//ferris_wheel
	"🎢",	//roller_coaster
	"💈",	//barber
	"🎪",	//circus_tent
	"🚂",	//steam_locomotive
	"🚃",	//railway_car
	"🚄",	//bullettrain_side
	"🚅",	//bullettrain_front
	"🚆",	//train2
	"🚇",	//metro
	"🚈",	//light_rail
	"🚉",	//station
	"🚊",	//tram
	"🚝",	//monorail
	"🚞",	//mountain_railway
	"🚋",	//train
	"🚌",	//bus
	"🚍",	//oncoming_bus
	"🚎",	//trolleybus
	"🚐",	//minibus
	"🚑",	//ambulance
	"🚒",	//fire_engine
	"🚓",	//police_car
	"🚔",	//oncoming_police_car
	"🚕",	//taxi
	"🚖",	//oncoming_taxi
	"🚗",	//car
	"🚗",	//red_car
	"🚘",	//oncoming_automobile
	"🚙",	//blue_car
	"🛻",	//pickup_truck
	"🚚",	//truck
	"🚛",	//articulated_lorry
	"🚜",	//tractor
	"🏎️",	//racing_car
	"🏍️",	//racing_motorcycle
	"🏍️",	//motorcycle
	"🛵",	//motor_scooter
	"🦽",	//manual_wheelchair
	"🦼",	//motorized_wheelchair
	"🛺",	//auto_rickshaw
	"🚲",	//bike
	"🛴",	//scooter
	"🛴",	//kick_scooter
	"🛹",	//skateboard
	"🛼",	//roller_skate
	"🚏",	//busstop
	"🛣️",	//motorway
	"🛤️",	//railway_track
	"🛢️",	//oil_drum
	"⛽",		//fuelpump
	"🚨",	//rotating_light
	"🚥",	//traffic_light
	"🚦",	//vertical_traffic_light
	"🛑",	//octagonal_sign
	"🛑",	//stop_sign
	"🚧",	//construction
	"⚓",		//anchor
	"⛵",		//boat
	"⛵",		//sailboat
	"🛶",	//canoe
	"🚤",	//speedboat
	"🛳️",	//passenger_ship
	"⛴️",	//ferry
	"🛥️",	//motor_boat
	"🚢",	//ship
	"✈️",	//airplane
	"🛩️",	//small_airplane
	"🛫",	//airplane_departure
	"🛫",	//flight_departure
	"🛬",	//airplane_arriving
	"🛬",	//flight_arrival
	"🪂",	//parachute
	"💺",	//seat
	"🚁",	//helicopter
	"🚟",	//suspension_railway
	"🚠",	//mountain_cableway
	"🚡",	//aerial_tramway
	"🛰️",	//satellite
	"🛰️",	//artificial_satellite
	"🚀",	//rocket
	"🛸",	//flying_saucer
	"🛎️",	//bellhop_bell
	"🧳",	//luggage
	"⌛",		//hourglass
	"⏳",		//hourglass_flowing_sand
	"⌚",		//watch
	"⏰",		//alarm_clock
	"⏱️",	//stopwatch
	"⏲️",	//timer_clock
	"🕰️",	//mantelpiece_clock
	"🕛",	//clock12
	"🕧",	//clock1230
	"🕐",	//clock1
	"🕜",	//clock130
	"🕑",	//clock2
	"🕝",	//clock230
	"🕒",	//clock3
	"🕞",	//clock330
	"🕓",	//clock4
	"🕟",	//clock430
	"🕔",	//clock5
	"🕠",	//clock530
	"🕕",	//clock6
	"🕡",	//clock630
	"🕖",	//clock7
	"🕢",	//clock730
	"🕗",	//clock8
	"🕣",	//clock830
	"🕘",	//clock9
	"🕤",	//clock930
	"🕙",	//clock10
	"🕥",	//clock1030
	"🕚",	//clock11
	"🕦",	//clock1130
	"🌑",	//new_moon
	"🌒",	//waxing_crescent_moon
	"🌓",	//first_quarter_moon
	"🌔",	//moon
	"🌔",	//waxing_gibbous_moon
	"🌕",	//full_moon
	"🌖",	//waning_gibbous_moon
	"🌗",	//last_quarter_moon
	"🌘",	//waning_crescent_moon
	"🌙",	//crescent_moon
	"🌚",	//new_moon_with_face
	"🌛",	//first_quarter_moon_with_face
	"🌜",	//last_quarter_moon_with_face
	"🌡️",	//thermometer
	"☀️",	//sunny
	"🌝",	//full_moon_with_face
	"🌞",	//sun_with_face
	"🪐",	//ringed_planet
	"⭐",		//star
	"🌟",	//star2
	"🌠",	//stars
	"🌌",	//milky_way
	"☁️",	//cloud
	"⛅",		//partly_sunny
	"⛈️",	//thunder_cloud_and_rain
	"⛈️",	//cloud_with_lightning_and_rain
	"🌤️",	//mostly_sunny
	"🌤️",	//sun_small_cloud
	"🌤️",	//sun_behind_small_cloud
	"🌥️",	//barely_sunny
	"🌥️",	//sun_behind_cloud
	"🌥️",	//sun_behind_large_cloud
	"🌦️",	//partly_sunny_rain
	"🌦️",	//sun_behind_rain_cloud
	"🌧️",	//rain_cloud
	"🌧️",	//cloud_with_rain
	"🌨️",	//snow_cloud
	"🌨️",	//cloud_with_snow
	"🌩️",	//lightning
	"🌩️",	//lightning_cloud
	"🌩️",	//cloud_with_lightning
	"🌪️",	//tornado
	"🌪️",	//tornado_cloud
	"🌫️",	//fog
	"🌬️",	//wind_blowing_face
	"🌬️",	//wind_face
	"🌀",	//cyclone
	"🌈",	//rainbow
	"🌂",	//closed_umbrella
	"☂️",	//umbrella
	"☂️",	//open_umbrella
	"☔",		//umbrella_with_rain_drops
	"⛱️",	//umbrella_on_ground
	"⛱️",	//parasol_on_ground
	"⚡",		//zap
	"❄️",	//snowflake
	"☃️",	//snowman
	"☃️",	//snowman_with_snow
	"⛄",		//snowman_without_snow
	"☄️",	//comet
	"🔥",	//fire
	"💧",	//droplet
	"🌊",	//ocean
	"🎃",	//jack_o_lantern
	"🎄",	//christmas_tree
	"🎆",	//fireworks
	"🎇",	//sparkler
	"🧨",	//firecracker
	"✨",		//sparkles
	"🎈",	//balloon
	"🎉",	//tada
	"🎊",	//confetti_ball
	"🎋",	//tanabata_tree
	"🎍",	//bamboo
	"🎎",	//dolls
	"🎏",	//flags
	"🎐",	//wind_chime
	"🎑",	//rice_scene
	"🧧",	//red_envelope
	"🎀",	//ribbon
	"🎁",	//gift
	"🎗️",	//reminder_ribbon
	"🎟️",	//admission_tickets
	"🎟️",	//tickets
	"🎫",	//ticket
	"🎖️",	//medal
	"🎖️",	//medal_military
	"🏆",	//trophy
	"🏅",	//sports_medal
	"🏅",	//medal_sports
	"🥇",	//first_place_medal
	"🥇",	//1st_place_medal
	"🥈",	//second_place_medal
	"🥈",	//2nd_place_medal
	"🥉",	//third_place_medal
	"🥉",	//3rd_place_medal
	"⚽",		//soccer
	"⚾",		//baseball
	"🥎",	//softball
	"🏀",	//basketball
	"🏐",	//volleyball
	"🏈",	//football
	"🏉",	//rugby_football
	"🎾",	//tennis
	"🥏",	//flying_disc
	"🎳",	//bowling
	"🏏",	//cricket_bat_and_ball
	"🏑",	//field_hockey_stick_and_ball
	"🏑",	//field_hockey
	"🏒",	//ice_hockey_stick_and_puck
	"🏒",	//ice_hockey
	"🥍",	//lacrosse
	"🏓",	//table_tennis_paddle_and_ball
	"🏓",	//ping_pong
	"🏸",	//badminton_racquet_and_shuttlecock
	"🏸",	//badminton
	"🥊",	//boxing_glove
	"🥋",	//martial_arts_uniform
	"🥅",	//goal_net
	"⛳",		//golf
	"⛸️",	//ice_skate
	"🎣",	//fishing_pole_and_fish
	"🤿",	//diving_mask
	"🎽",	//running_shirt_with_sash
	"🎿",	//ski
	"🛷",	//sled
	"🥌",	//curling_stone
	"🎯",	//dart
	"🪀",	//yo-yo
	"🪁",	//kite
	"🎱",	//8ball
	"🔮",	//crystal_ball
	"🪄",	//magic_wand
	"🧿",	//nazar_amulet
	"🎮",	//video_game
	"🕹️",	//joystick
	"🎰",	//slot_machine
	"🎲",	//game_die
	"🧩",	//jigsaw
	"🧸",	//teddy_bear
	"🪅",	//pinata
	"🪆",	//nesting_dolls
	"♠️",	//spades
	"♥️",	//hearts
	"♦️",	//diamonds
	"♣️",	//clubs
	"♟️",	//chess_pawn
	"🃏",	//black_joker
	"🀄",	//mahjong
	"🎴",	//flower_playing_cards
	"🎭",	//performing_arts
	"🖼️",	//frame_with_picture
	"🖼️",	//framed_picture
	"🎨",	//art
	"🧵",	//thread
	"🪡",	//sewing_needle
	"🧶",	//yarn
	"🪢",	//knot
	"👓",	//eyeglasses
	"🕶️",	//dark_sunglasses
	"🥽",	//goggles
	"🥼",	//lab_coat
	"🦺",	//safety_vest
	"👔",	//necktie
	"👕",	//shirt
	"👕",	//tshirt
	"👖",	//jeans
	"🧣",	//scarf
	"🧤",	//gloves
	"🧥",	//coat
	"🧦",	//socks
	"👗",	//dress
	"👘",	//kimono
	"🥻",	//sari
	"🩱",	//one-piece_swimsuit
	"🩲",	//briefs
	"🩳",	//shorts
	"👙",	//bikini
	"👚",	//womans_clothes
	"👛",	//purse
	"👜",	//handbag
	"👝",	//pouch
	"🛍️",	//shopping_bags
	"🛍️",	//shopping
	"🎒",	//school_satchel
	"🩴",	//thong_sandal
	"👞",	//mans_shoe
	"👞",	//shoe
	"👟",	//athletic_shoe
	"🥾",	//hiking_boot
	"🥿",	//womans_flat_shoe
	"👠",	//high_heel
	"👡",	//sandal
	"🩰",	//ballet_shoes
	"👢",	//boot
	"👑",	//crown
	"👒",	//womans_hat
	"🎩",	//tophat
	"🎓",	//mortar_board
	"🧢",	//billed_cap
	"🪖",	//military_helmet
	"⛑️",	//helmet_with_white_cross
	"⛑️",	//rescue_worker_helmet
	"📿",	//prayer_beads
	"💄",	//lipstick
	"💍",	//ring
	"💎",	//gem
	"🔇",	//mute
	"🔈",	//speaker
	"🔉",	//sound
	"🔊",	//loud_sound
	"📢",	//loudspeaker
	"📣",	//mega
	"📯",	//postal_horn
	"🔔",	//bell
	"🔕",	//no_bell
	"🎼",	//musical_score
	"🎵",	//musical_note
	"🎶",	//notes
	"🎙️",	//studio_microphone
	"🎚️",	//level_slider
	"🎛️",	//control_knobs
	"🎤",	//microphone
	"🎧",	//headphones
	"📻",	//radio
	"🎷",	//saxophone
	"🪗",	//accordion
	"🎸",	//guitar
	"🎹",	//musical_keyboard
	"🎺",	//trumpet
	"🎻",	//violin
	"🪕",	//banjo
	"🥁",	//drum_with_drumsticks
	"🥁",	//drum
	"🪘",	//long_drum
	"📱",	//iphone
	"📲",	//calling
	"☎️",	//phone
	"☎️",	//telephone
	"📞",	//telephone_receiver
	"📟",	//pager
	"📠",	//fax
	"🔋",	//battery
	"🔌",	//electric_plug
	"💻",	//computer
	"🖥️",	//desktop_computer
	"🖨️",	//printer
	"⌨️",	//keyboard
	"🖱️",	//three_button_mouse
	"🖱️",	//computer_mouse
	"🖲️",	//trackball
	"💽",	//minidisc
	"💾",	//floppy_disk
	"💿",	//cd
	"📀",	//dvd
	"🧮",	//abacus
	"🎥",	//movie_camera
	"🎞️",	//film_frames
	"🎞️",	//film_strip
	"📽️",	//film_projector
	"🎬",	//clapper
	"📺",	//tv
	"📷",	//camera
	"📸",	//camera_with_flash
	"📸",	//camera_flash
	"📹",	//video_camera
	"📼",	//vhs
	"🔍",	//mag
	"🔎",	//mag_right
	"🕯️",	//candle
	"💡",	//bulb
	"🔦",	//flashlight
	"🏮",	//izakaya_lantern
	"🏮",	//lantern
	"🪔",	//diya_lamp
	"📔",	//notebook_with_decorative_cover
	"📕",	//closed_book
	"📖",	//book
	"📖",	//open_book
	"📗",	//green_book
	"📘",	//blue_book
	"📙",	//orange_book
	"📚",	//books
	"📓",	//notebook
	"📒",	//ledger
	"📃",	//page_with_curl
	"📜",	//scroll
	"📄",	//page_facing_up
	"📰",	//newspaper
	"🗞️",	//rolled_up_newspaper
	"🗞️",	//newspaper_roll
	"📑",	//bookmark_tabs
	"🔖",	//bookmark
	"🏷️",	//label
	"💰",	//moneybag
	"🪙",	//coin
	"💴",	//yen
	"💵",	//dollar
	"💶",	//euro
	"💷",	//pound
	"💸",	//money_with_wings
	"💳",	//credit_card
	"🧾",	//receipt
	"💹",	//chart
	"✉️",	//email
	"✉️",	//envelope
	"📧",	//e-mail
	"📨",	//incoming_envelope
	"📩",	//envelope_with_arrow
	"📤",	//outbox_tray
	"📥",	//inbox_tray
	"📦",	//package
	"📫",	//mailbox
	"📪",	//mailbox_closed
	"📬",	//mailbox_with_mail
	"📭",	//mailbox_with_no_mail
	"📮",	//postbox
	"🗳️",	//ballot_box_with_ballot
	"🗳️",	//ballot_box
	"✏️",	//pencil2
	"✒️",	//black_nib
	"🖋️",	//lower_left_fountain_pen
	"🖋️",	//fountain_pen
	"🖊️",	//lower_left_ballpoint_pen
	"🖊️",	//pen
	"🖌️",	//lower_left_paintbrush
	"🖌️",	//paintbrush
	"🖍️",	//lower_left_crayon
	"🖍️",	//crayon
	"📝",	//memo
	"📝",	//pencil
	"💼",	//briefcase
	"📁",	//file_folder
	"📂",	//open_file_folder
	"🗂️",	//card_index_dividers
	"📅",	//date
	"📆",	//calendar
	"🗒️",	//spiral_note_pad
	"🗒️",	//spiral_notepad
	"🗓️",	//spiral_calendar_pad
	"🗓️",	//spiral_calendar
	"📇",	//card_index
	"📈",	//chart_with_upwards_trend
	"📉",	//chart_with_downwards_trend
	"📊",	//bar_chart
	"📋",	//clipboard
	"📌",	//pushpin
	"📍",	//round_pushpin
	"📎",	//paperclip
	"🖇️",	//linked_paperclips
	"🖇️",	//paperclips
	"📏",	//straight_ruler
	"📐",	//triangular_ruler
	"✂️",	//scissors
	"🗃️",	//card_file_box
	"🗄️",	//file_cabinet
	"🗑️",	//wastebasket
	"🔒",	//lock
	"🔓",	//unlock
	"🔏",	//lock_with_ink_pen
	"🔐",	//closed_lock_with_key
	"🔑",	//key
	"🗝️",	//old_key
	"🔨",	//hammer
	"🪓",	//axe
	"⛏️",	//pick
	"⚒️",	//hammer_and_pick
	"🛠️",	//hammer_and_wrench
	"🗡️",	//dagger_knife
	"🗡️",	//dagger
	"⚔️",	//crossed_swords
	"🔫",	//gun
	"🪃",	//boomerang
	"🏹",	//bow_and_arrow
	"🛡️",	//shield
	"🪚",	//carpentry_saw
	"🔧",	//wrench
	"🪛",	//screwdriver
	"🔩",	//nut_and_bolt
	"⚙️",	//gear
	"🗜️",	//compression
	"🗜️",	//clamp
	"⚖️",	//scales
	"⚖️",	//balance_scale
	"🦯",	//probing_cane
	"🔗",	//link
	"⛓️",	//chains
	"🪝",	//hook
	"🧰",	//toolbox
	"🧲",	//magnet
	"🪜",	//ladder
	"⚗️",	//alembic
	"🧪",	//test_tube
	"🧫",	//petri_dish
	"🧬",	//dna
	"🔬",	//microscope
	"🔭",	//telescope
	"📡",	//satellite_antenna
	"💉",	//syringe
	"🩸",	//drop_of_blood
	"💊",	//pill
	"🩹",	//adhesive_bandage
	"🩺",	//stethoscope
	"🚪",	//door
	"🛗",	//elevator
	"🪞",	//mirror
	"🪟",	//window
	"🛏️",	//bed
	"🛋️",	//couch_and_lamp
	"🪑",	//chair
	"🚽",	//toilet
	"🪠",	//plunger
	"🚿",	//shower
	"🛁",	//bathtub
	"🪤",	//mouse_trap
	"🪒",	//razor
	"🧴",	//lotion_bottle
	"🧷",	//safety_pin
	"🧹",	//broom
	"🧺",	//basket
	"🧻",	//roll_of_paper
	"🪣",	//bucket
	"🧼",	//soap
	"🪥",	//toothbrush
	"🧽",	//sponge
	"🧯",	//fire_extinguisher
	"🛒",	//shopping_trolley
	"🛒",	//shopping_cart
	"🚬",	//smoking
	"⚰️",	//coffin
	"🪦",	//headstone
	"⚱️",	//funeral_urn
	"🗿",	//moyai
	"🪧",	//placard
	"🏧",	//atm
	"🚮",	//put_litter_in_its_place
	"🚰",	//potable_water
	"♿",		//wheelchair
	"🚹",	//mens
	"🚺",	//womens
	"🚻",	//restroom
	"🚼",	//baby_symbol
	"🚾",	//wc
	"🛂",	//passport_control
	"🛃",	//customs
	"🛄",	//baggage_claim
	"🛅",	//left_luggage
	"⚠️",	//warning
	"🚸",	//children_crossing
	"⛔",		//no_entry
	"🚫",	//no_entry_sign
	"🚳",	//no_bicycles
	"🚭",	//no_smoking
	"🚯",	//do_not_litter
	"🚱",	//non-potable_water
	"🚷",	//no_pedestrians
	"📵",	//no_mobile_phones
	"🔞",	//underage
	"☢️",	//radioactive_sign
	"☢️",	//radioactive
	"☣️",	//biohazard_sign
	"☣️",	//biohazard
	"⬆️",	//arrow_up
	"↗️",	//arrow_upper_right
	"➡️",	//arrow_right
	"↘️",	//arrow_lower_right
	"⬇️",	//arrow_down
	"↙️",	//arrow_lower_left
	"⬅️",	//arrow_left
	"↖️",	//arrow_upper_left
	"↕️",	//arrow_up_down
	"↔️",	//left_right_arrow
	"↩️",	//leftwards_arrow_with_hook
	"↪️",	//arrow_right_hook
	"⤴️",	//arrow_heading_up
	"⤵️",	//arrow_heading_down
	"🔃",	//arrows_clockwise
	"🔄",	//arrows_counterclockwise
	"🔙",	//back
	"🔚",	//end
	"🔛",	//on
	"🔜",	//soon
	"🔝",	//top
	"🛐",	//place_of_worship
	"⚛️",	//atom_symbol
	"🕉️",	//om_symbol
	"🕉️",	//om
	"✡️",	//star_of_david
	"☸️",	//wheel_of_dharma
	"☯️",	//yin_yang
	"✝️",	//latin_cross
	"☦️",	//orthodox_cross
	"☪️",	//star_and_crescent
	"☮️",	//peace_symbol
	"🕎",	//menorah_with_nine_branches
	"🕎",	//menorah
	"🔯",	//six_pointed_star
	"♈",		//aries
	"♉",		//taurus
	"♊",		//gemini
	"♋",		//cancer
	"♌",		//leo
	"♍",		//virgo
	"♎",		//libra
	"♏",		//scorpius
	"♐",		//sagittarius
	"♑",		//capricorn
	"♒",		//aquarius
	"♓",		//pisces
	"⛎",		//ophiuchus
	"🔀",	//twisted_rightwards_arrows
	"🔁",	//repeat
	"🔂",	//repeat_one
	"▶️",	//arrow_forward
	"⏩",		//fast_forward
	"⏭️",	//black_right_pointing_double_triangle_with_vertical_bar
	"⏭️",	//next_track_button
	"⏯️",	//black_right_pointing_triangle_with_double_vertical_bar
	"⏯️",	//play_or_pause_button
	"◀️",	//arrow_backward
	"⏪",		//rewind
	"⏮️",	//black_left_pointing_double_triangle_with_vertical_bar
	"⏮️",	//previous_track_button
	"🔼",	//arrow_up_small
	"⏫",		//arrow_double_up
	"🔽",	//arrow_down_small
	"⏬",		//arrow_double_down
	"⏸️",	//double_vertical_bar
	"⏸️",	//pause_button
	"⏹️",	//black_square_for_stop
	"⏹️",	//stop_button
	"⏺️",	//black_circle_for_record
	"⏺️",	//record_button
	"⏏️",	//eject
	"🎦",	//cinema
	"🔅",	//low_brightness
	"🔆",	//high_brightness
	"📶",	//signal_strength
	"📳",	//vibration_mode
	"📴",	//mobile_phone_off
	"♀️",	//female_sign
	"♂️",	//male_sign
	"⚧️",	//transgender_symbol
	"✖️",	//heavy_multiplication_x
	"➕",		//heavy_plus_sign
	"➖",		//heavy_minus_sign
	"➗",		//heavy_division_sign
	"♾️",	//infinity
	"‼️",	//bangbang
	"⁉️",	//interrobang
	"❓",		//question
	"❔",		//grey_question
	"❕",		//grey_exclamation
	"❗",		//exclamation
	"❗",		//heavy_exclamation_mark
	"〰️",	//wavy_dash
	"💱",	//currency_exchange
	"💲",	//heavy_dollar_sign
	"⚕️",	//medical_symbol
	"⚕️",	//staff_of_aesculapius
	"♻️",	//recycle
	"⚜️",	//fleur_de_lis
	"🔱",	//trident
	"📛",	//name_badge
	"🔰",	//beginner
	"⭕",		//o
	"✅",		//white_check_mark
	"☑️",	//ballot_box_with_check
	"✔️",	//heavy_check_mark
	"❌",		//x
	"❎",		//negative_squared_cross_mark
	"➰",		//curly_loop
	"➿",		//loop
	"〽️",	//part_alternation_mark
	"✳️",	//eight_spoked_asterisk
	"✴️",	//eight_pointed_black_star
	"❇️",	//sparkle
	"©️",	//copyright
	"®️",	//registered
	"™️",	//tm
	"#️⃣",	//hash
	"*️⃣",	//keycap_star
	"*️⃣",	//asterisk
	"0️⃣",	//zero
	"1️⃣",	//one
	"2️⃣",	//two
	"3️⃣",	//three
	"4️⃣",	//four
	"5️⃣",	//five
	"6️⃣",	//six
	"7️⃣",	//seven
	"8️⃣",	//eight
	"9️⃣",	//nine
	"🔟",	//keycap_ten
	"🔠",	//capital_abcd
	"🔡",	//abcd
	"🔢",	//1234
	"🔣",	//symbols
	"🔤",	//abc
	"🅰️",	//a
	"🆎",	//ab
	"🅱️",	//b
	"🆑",	//cl
	"🆒",	//cool
	"🆓",	//free
	"ℹ️",	//information_source
	"🆔",	//id
	"Ⓜ️",	//m
	"🆕",	//new
	"🆖",	//ng
	"🅾️",	//o2
	"🆗",	//ok
	"🅿️",	//parking
	"🆘",	//sos
	"🆙",	//up
	"🆚",	//vs
	"🈁",	//koko
	"🈂️",	//sa
	"🈷️",	//u6708
	"🈶",	//u6709
	"🈯",	//u6307
	"🉐",	//ideograph_advantage
	"🈹",	//u5272
	"🈚",	//u7121
	"🈲",	//u7981
	"🉑",	//accept
	"🈸",	//u7533
	"🈴",	//u5408
	"🈳",	//u7a7a
	"㊗️",	//congratulations
	"㊙️",	//secret
	"🈺",	//u55b6
	"🈵",	//u6e80
	"🔴",	//red_circle
	"🟠",	//large_orange_circle
	"🟡",	//large_yellow_circle
	"🟢",	//large_green_circle
	"🔵",	//large_blue_circle
	"🟣",	//large_purple_circle
	"🟤",	//large_brown_circle
	"⚫",		//black_circle
	"⚪",		//white_circle
	"🟥",	//large_red_square
	"🟧",	//large_orange_square
	"🟨",	//large_yellow_square
	"🟩",	//large_green_square
	"🟦",	//large_blue_square
	"🟪",	//large_purple_square
	"🟫",	//large_brown_square
	"⬛",		//black_large_square
	"⬜",		//white_large_square
	"◼️",	//black_medium_square
	"◻️",	//white_medium_square
	"◾",		//black_medium_small_square
	"◽",		//white_medium_small_square
	"▪️",	//black_small_square
	"▫️",	//white_small_square
	"🔶",	//large_orange_diamond
	"🔷",	//large_blue_diamond
	"🔸",	//small_orange_diamond
	"🔹",	//small_blue_diamond
	"🔺",	//small_red_triangle
	"🔻",	//small_red_triangle_down
	"💠",	//diamond_shape_with_a_dot_inside
	"🔘",	//radio_button
	"🔳",	//white_square_button
	"🔲",	//black_square_button
	"🏁",	//checkered_flag
	"🚩",	//triangular_flag_on_post
	"🎌",	//crossed_flags
	"🏴",	//waving_black_flag
	"🏴",	//black_flag
	"🏳️",	//waving_white_flag
	"🏳️",	//white_flag
	"🏳️‍🌈",	//rainbow-flag
	"🏳️‍🌈",	//rainbow_flag
	"🏳️‍⚧️",	//transgender_flag
	"🏴‍☠️",	//pirate_flag
	"🇦🇨",	//flag-ac
	"🇦🇩",	//flag-ad
	"🇦🇩",	//andorra
	"🇦🇪",	//flag-ae
	"🇦🇪",	//united_arab_emirates
	"🇦🇫",	//flag-af
	"🇦🇫",	//afghanistan
	"🇦🇬",	//flag-ag
	"🇦🇬",	//antigua_barbuda
	"🇦🇮",	//flag-ai
	"🇦🇮",	//anguilla
	"🇦🇱",	//flag-al
	"🇦🇱",	//albania
	"🇦🇲",	//flag-am
	"🇦🇲",	//armenia
	"🇦🇴",	//flag-ao
	"🇦🇴",	//angola
	"🇦🇶",	//flag-aq
	"🇦🇶",	//antarctica
	"🇦🇷",	//flag-ar
	"🇦🇷",	//argentina
	"🇦🇸",	//flag-as
	"🇦🇸",	//american_samoa
	"🇦🇹",	//flag-at
	"🇦🇹",	//austria
	"🇦🇺",	//flag-au
	"🇦🇺",	//australia
	"🇦🇼",	//flag-aw
	"🇦🇼",	//aruba
	"🇦🇽",	//flag-ax
	"🇦🇽",	//aland_islands
	"🇦🇿",	//flag-az
	"🇦🇿",	//azerbaijan
	"🇧🇦",	//flag-ba
	"🇧🇦",	//bosnia_herzegovina
	"🇧🇧",	//flag-bb
	"🇧🇧",	//barbados
	"🇧🇩",	//flag-bd
	"🇧🇩",	//bangladesh
	"🇧🇪",	//flag-be
	"🇧🇪",	//belgium
	"🇧🇫",	//flag-bf
	"🇧🇫",	//burkina_faso
	"🇧🇬",	//flag-bg
	"🇧🇬",	//bulgaria
	"🇧🇭",	//flag-bh
	"🇧🇭",	//bahrain
	"🇧🇮",	//flag-bi
	"🇧🇮",	//burundi
	"🇧🇯",	//flag-bj
	"🇧🇯",	//benin
	"🇧🇱",	//flag-bl
	"🇧🇱",	//st_barthelemy
	"🇧🇲",	//flag-bm
	"🇧🇲",	//bermuda
	"🇧🇳",	//flag-bn
	"🇧🇳",	//brunei
	"🇧🇴",	//flag-bo
	"🇧🇴",	//bolivia
	"🇧🇶",	//flag-bq
	"🇧🇶",	//caribbean_netherlands
	"🇧🇷",	//flag-br
	"🇧🇷",	//brazil
	"🇧🇸",	//flag-bs
	"🇧🇸",	//bahamas
	"🇧🇹",	//flag-bt
	"🇧🇹",	//bhutan
	"🇧🇻",	//flag-bv
	"🇧🇼",	//flag-bw
	"🇧🇼",	//botswana
	"🇧🇾",	//flag-by
	"🇧🇾",	//belarus
	"🇧🇿",	//flag-bz
	"🇧🇿",	//belize
	"🇨🇦",	//flag-ca
	"🇨🇦",	//ca
	"🇨🇦",	//canada
	"🇨🇨",	//flag-cc
	"🇨🇨",	//cocos_islands
	"🇨🇩",	//flag-cd
	"🇨🇩",	//congo_kinshasa
	"🇨🇫",	//flag-cf
	"🇨🇫",	//central_african_republic
	"🇨🇬",	//flag-cg
	"🇨🇬",	//congo_brazzaville
	"🇨🇭",	//flag-ch
	"🇨🇭",	//switzerland
	"🇨🇮",	//flag-ci
	"🇨🇮",	//cote_divoire
	"🇨🇰",	//flag-ck
	"🇨🇰",	//cook_islands
	"🇨🇱",	//flag-cl
	"🇨🇱",	//chile
	"🇨🇲",	//flag-cm
	"🇨🇲",	//cameroon
	"🇨🇳",	//cn
	"🇨🇳",	//flag-cn
	"🇨🇴",	//flag-co
	"🇨🇴",	//colombia
	"🇨🇵",	//flag-cp
	"🇨🇷",	//flag-cr
	"🇨🇷",	//costa_rica
	"🇨🇺",	//flag-cu
	"🇨🇺",	//cuba
	"🇨🇻",	//flag-cv
	"🇨🇻",	//cape_verde
	"🇨🇼",	//flag-cw
	"🇨🇼",	//curacao
	"🇨🇽",	//flag-cx
	"🇨🇽",	//christmas_island
	"🇨🇾",	//flag-cy
	"🇨🇾",	//cyprus
	"🇨🇿",	//flag-cz
	"🇨🇿",	//czech_republic
	"🇩🇪",	//de
	"🇩🇪",	//flag-de
	"🇩🇬",	//flag-dg
	"🇩🇯",	//flag-dj
	"🇩🇯",	//djibouti
	"🇩🇰",	//flag-dk
	"🇩🇰",	//denmark
	"🇩🇲",	//flag-dm
	"🇩🇲",	//dominica
	"🇩🇴",	//flag-do
	"🇩🇴",	//dominican_republic
	"🇩🇿",	//flag-dz
	"🇩🇿",	//algeria
	"🇪🇦",	//flag-ea
	"🇪🇨",	//flag-ec
	"🇪🇨",	//ecuador
	"🇪🇪",	//flag-ee
	"🇪🇪",	//estonia
	"🇪🇬",	//flag-eg
	"🇪🇬",	//egypt
	"🇪🇭",	//flag-eh
	"🇪🇭",	//western_sahara
	"🇪🇷",	//flag-er
	"🇪🇷",	//eritrea
	"🇪🇸",	//es
	"🇪🇸",	//flag-es
	"🇪🇹",	//flag-et
	"🇪🇹",	//ethiopia
	"🇪🇺",	//flag-eu
	"🇪🇺",	//eu
	"🇪🇺",	//european_union
	"🇫🇮",	//flag-fi
	"🇫🇮",	//finland
	"🇫🇯",	//flag-fj
	"🇫🇯",	//fiji
	"🇫🇰",	//flag-fk
	"🇫🇰",	//falkland_islands
	"🇫🇲",	//flag-fm
	"🇫🇲",	//micronesia
	"🇫🇴",	//flag-fo
	"🇫🇴",	//faroe_islands
	"🇫🇷",	//fr
	"🇫🇷",	//flag-fr
	"🇬🇦",	//flag-ga
	"🇬🇦",	//gabon
	"🇬🇧",	//gb
	"🇬🇧",	//uk
	"🇬🇧",	//flag-gb
	"🇬🇩",	//flag-gd
	"🇬🇩",	//grenada
	"🇬🇪",	//flag-ge
	"🇬🇪",	//georgia
	"🇬🇫",	//flag-gf
	"🇬🇫",	//french_guiana
	"🇬🇬",	//flag-gg
	"🇬🇬",	//guernsey
	"🇬🇭",	//flag-gh
	"🇬🇭",	//ghana
	"🇬🇮",	//flag-gi
	"🇬🇮",	//gibraltar
	"🇬🇱",	//flag-gl
	"🇬🇱",	//greenland
	"🇬🇲",	//flag-gm
	"🇬🇲",	//gambia
	"🇬🇳",	//flag-gn
	"🇬🇳",	//guinea
	"🇬🇵",	//flag-gp
	"🇬🇵",	//guadeloupe
	"🇬🇶",	//flag-gq
	"🇬🇶",	//equatorial_guinea
	"🇬🇷",	//flag-gr
	"🇬🇷",	//greece
	"🇬🇸",	//flag-gs
	"🇬🇸",	//south_georgia_south_sandwich_islands
	"🇬🇹",	//flag-gt
	"🇬🇹",	//guatemala
	"🇬🇺",	//flag-gu
	"🇬🇺",	//guam
	"🇬🇼",	//flag-gw
	"🇬🇼",	//guinea_bissau
	"🇬🇾",	//flag-gy
	"🇬🇾",	//guyana
	"🇭🇰",	//flag-hk
	"🇭🇰",	//hong_kong
	"🇭🇲",	//flag-hm
	"🇭🇳",	//flag-hn
	"🇭🇳",	//honduras
	"🇭🇷",	//flag-hr
	"🇭🇷",	//croatia
	"🇭🇹",	//flag-ht
	"🇭🇹",	//haiti
	"🇭🇺",	//flag-hu
	"🇭🇺",	//hungary
	"🇮🇨",	//flag-ic
	"🇮🇨",	//canary_islands
	"🇮🇩",	//flag-id
	"🇮🇩",	//indonesia
	"🇮🇪",	//flag-ie
	"🇮🇪",	//ireland
	"🇮🇱",	//flag-il
	"🇮🇱",	//israel
	"🇮🇲",	//flag-im
	"🇮🇲",	//isle_of_man
	"🇮🇳",	//flag-in
	"🇮🇳",	//india
	"🇮🇴",	//flag-io
	"🇮🇴",	//british_indian_ocean_territory
	"🇮🇶",	//flag-iq
	"🇮🇶",	//iraq
	"🇮🇷",	//flag-ir
	"🇮🇷",	//iran
	"🇮🇸",	//flag-is
	"🇮🇸",	//iceland
	"🇮🇹",	//it
	"🇮🇹",	//flag-it
	"🇯🇪",	//flag-je
	"🇯🇪",	//jersey
	"🇯🇲",	//flag-jm
	"🇯🇲",	//jamaica
	"🇯🇴",	//flag-jo
	"🇯🇴",	//jordan
	"🇯🇵",	//jp
	"🇯🇵",	//flag-jp
	"🇰🇪",	//flag-ke
	"🇰🇪",	//kenya
	"🇰🇬",	//flag-kg
	"🇰🇬",	//kyrgyzstan
	"🇰🇭",	//flag-kh
	"🇰🇭",	//cambodia
	"🇰🇮",	//flag-ki
	"🇰🇮",	//kiribati
	"🇰🇲",	//flag-km
	"🇰🇲",	//comoros
	"🇰🇳",	//flag-kn
	"🇰🇳",	//st_kitts_nevis
	"🇰🇵",	//flag-kp
	"🇰🇵",	//north_korea
	"🇰🇷",	//kr
	"🇰🇷",	//flag-kr
	"🇰🇼",	//flag-kw
	"🇰🇼",	//kuwait
	"🇰🇾",	//flag-ky
	"🇰🇾",	//cayman_islands
	"🇰🇿",	//flag-kz
	"🇰🇿",	//kazakhstan
	"🇱🇦",	//flag-la
	"🇱🇦",	//laos
	"🇱🇧",	//flag-lb
	"🇱🇧",	//lebanon
	"🇱🇨",	//flag-lc
	"🇱🇨",	//st_lucia
	"🇱🇮",	//flag-li
	"🇱🇮",	//liechtenstein
	"🇱🇰",	//flag-lk
	"🇱🇰",	//sri_lanka
	"🇱🇷",	//flag-lr
	"🇱🇷",	//liberia
	"🇱🇸",	//flag-ls
	"🇱🇸",	//lesotho
	"🇱🇹",	//flag-lt
	"🇱🇹",	//lithuania
	"🇱🇺",	//flag-lu
	"🇱🇺",	//luxembourg
	"🇱🇻",	//flag-lv
	"🇱🇻",	//latvia
	"🇱🇾",	//flag-ly
	"🇱🇾",	//libya
	"🇲🇦",	//flag-ma
	"🇲🇦",	//morocco
	"🇲🇨",	//flag-mc
	"🇲🇨",	//monaco
	"🇲🇩",	//flag-md
	"🇲🇩",	//moldova
	"🇲🇪",	//flag-me
	"🇲🇪",	//montenegro
	"🇲🇫",	//flag-mf
	"🇲🇬",	//flag-mg
	"🇲🇬",	//madagascar
	"🇲🇭",	//flag-mh
	"🇲🇭",	//marshall_islands
	"🇲🇰",	//flag-mk
	"🇲🇰",	//macedonia
	"🇲🇱",	//flag-ml
	"🇲🇱",	//mali
	"🇲🇲",	//flag-mm
	"🇲🇲",	//myanmar
	"🇲🇳",	//flag-mn
	"🇲🇳",	//mongolia
	"🇲🇴",	//flag-mo
	"🇲🇴",	//macau
	"🇲🇵",	//flag-mp
	"🇲🇵",	//northern_mariana_islands
	"🇲🇶",	//flag-mq
	"🇲🇶",	//martinique
	"🇲🇷",	//flag-mr
	"🇲🇷",	//mauritania
	"🇲🇸",	//flag-ms
	"🇲🇸",	//montserrat
	"🇲🇹",	//flag-mt
	"🇲🇹",	//malta
	"🇲🇺",	//flag-mu
	"🇲🇺",	//mauritius
	"🇲🇻",	//flag-mv
	"🇲🇻",	//maldives
	"🇲🇼",	//flag-mw
	"🇲🇼",	//malawi
	"🇲🇽",	//flag-mx
	"🇲🇽",	//mexico
	"🇲🇾",	//flag-my
	"🇲🇾",	//malaysia
	"🇲🇿",	//flag-mz
	"🇲🇿",	//mozambique
	"🇳🇦",	//flag-na
	"🇳🇦",	//namibia
	"🇳🇨",	//flag-nc
	"🇳🇨",	//new_caledonia
	"🇳🇪",	//flag-ne
	"🇳🇪",	//niger
	"🇳🇫",	//flag-nf
	"🇳🇫",	//norfolk_island
	"🇳🇬",	//flag-ng
	"🇳🇬",	//nigeria
	"🇳🇮",	//flag-ni
	"🇳🇮",	//nicaragua
	"🇳🇱",	//flag-nl
	"🇳🇱",	//netherlands
	"🇳🇴",	//flag-no
	"🇳🇴",	//norway
	"🇳🇵",	//flag-np
	"🇳🇵",	//nepal
	"🇳🇷",	//flag-nr
	"🇳🇷",	//nauru
	"🇳🇺",	//flag-nu
	"🇳🇺",	//niue
	"🇳🇿",	//flag-nz
	"🇳🇿",	//new_zealand
	"🇴🇲",	//flag-om
	"🇴🇲",	//oman
	"🇵🇦",	//flag-pa
	"🇵🇦",	//panama
	"🇵🇪",	//flag-pe
	"🇵🇪",	//peru
	"🇵🇫",	//flag-pf
	"🇵🇫",	//french_polynesia
	"🇵🇬",	//flag-pg
	"🇵🇬",	//papua_new_guinea
	"🇵🇭",	//flag-ph
	"🇵🇭",	//philippines
	"🇵🇰",	//flag-pk
	"🇵🇰",	//pakistan
	"🇵🇰",	//pk
	"🇵🇱",	//flag-pl
	"🇵🇱",	//poland
	"🇵🇲",	//flag-pm
	"🇵🇲",	//st_pierre_miquelon
	"🇵🇳",	//flag-pn
	"🇵🇳",	//pitcairn_islands
	"🇵🇷",	//flag-pr
	"🇵🇷",	//puerto_rico
	"🇵🇸",	//flag-ps
	"🇵🇸",	//palestinian_territories
	"🇵🇹",	//flag-pt
	"🇵🇹",	//portugal
	"🇵🇼",	//flag-pw
	"🇵🇼",	//palau
	"🇵🇾",	//flag-py
	"🇵🇾",	//paraguay
	"🇶🇦",	//flag-qa
	"🇶🇦",	//qatar
	"🇷🇪",	//flag-re
	"🇷🇪",	//reunion
	"🇷🇴",	//flag-ro
	"🇷🇴",	//romania
	"🇷🇸",	//flag-rs
	"🇷🇸",	//serbia
	"🇷🇺",	//ru
	"🇷🇺",	//flag-ru
	"🇷🇼",	//flag-rw
	"🇷🇼",	//rwanda
	"🇸🇦",	//flag-sa
	"🇸🇦",	//saudi_arabia
	"🇸🇧",	//flag-sb
	"🇸🇧",	//solomon_islands
	"🇸🇨",	//flag-sc
	"🇸🇨",	//seychelles
	"🇸🇩",	//flag-sd
	"🇸🇩",	//sudan
	"🇸🇪",	//flag-se
	"🇸🇪",	//sweden
	"🇸🇬",	//flag-sg
	"🇸🇬",	//singapore
	"🇸🇭",	//flag-sh
	"🇸🇭",	//st_helena
	"🇸🇮",	//flag-si
	"🇸🇮",	//slovenia
	"🇸🇯",	//flag-sj
	"🇸🇰",	//flag-sk
	"🇸🇰",	//slovakia
	"🇸🇱",	//flag-sl
	"🇸🇱",	//sierra_leone
	"🇸🇲",	//flag-sm
	"🇸🇲",	//san_marino
	"🇸🇳",	//flag-sn
	"🇸🇳",	//senegal
	"🇸🇴",	//flag-so
	"🇸🇴",	//somalia
	"🇸🇷",	//flag-sr
	"🇸🇷",	//suriname
	"🇸🇸",	//flag-ss
	"🇸🇸",	//south_sudan
	"🇸🇹",	//flag-st
	"🇸🇹",	//sao_tome_principe
	"🇸🇻",	//flag-sv
	"🇸🇻",	//el_salvador
	"🇸🇽",	//flag-sx
	"🇸🇽",	//sint_maarten
	"🇸🇾",	//flag-sy
	"🇸🇾",	//syria
	"🇸🇿",	//flag-sz
	"🇸🇿",	//swaziland
	"🇹🇦",	//flag-ta
	"🇹🇨",	//flag-tc
	"🇹🇨",	//turks_caicos_islands
	"🇹🇩",	//flag-td
	"🇹🇩",	//chad
	"🇹🇫",	//flag-tf
	"🇹🇫",	//french_southern_territories
	"🇹🇬",	//flag-tg
	"🇹🇬",	//togo
	"🇹🇭",	//flag-th
	"🇹🇭",	//thailand
	"🇹🇯",	//flag-tj
	"🇹🇯",	//tajikistan
	"🇹🇰",	//flag-tk
	"🇹🇰",	//tokelau
	"🇹🇱",	//flag-tl
	"🇹🇱",	//timor_leste
	"🇹🇲",	//flag-tm
	"🇹🇲",	//turkmenistan
	"🇹🇳",	//flag-tn
	"🇹🇳",	//tunisia
	"🇹🇴",	//flag-to
	"🇹🇴",	//tonga
	"🇹🇷",	//flag-tr
	"🇹🇷",	//tr
	"🇹🇹",	//flag-tt
	"🇹🇹",	//trinidad_tobago
	"🇹🇻",	//flag-tv
	"🇹🇻",	//tuvalu
	"🇹🇼",	//flag-tw
	"🇹🇼",	//taiwan
	"🇹🇿",	//flag-tz
	"🇹🇿",	//tanzania
	"🇺🇦",	//flag-ua
	"🇺🇦",	//ukraine
	"🇺🇬",	//flag-ug
	"🇺🇬",	//uganda
	"🇺🇲",	//flag-um
	"🇺🇳",	//flag-un
	"🇺🇸",	//us
	"🇺🇸",	//flag-us
	"🇺🇾",	//flag-uy
	"🇺🇾",	//uruguay
	"🇺🇿",	//flag-uz
	"🇺🇿",	//uzbekistan
	"🇻🇦",	//flag-va
	"🇻🇦",	//vatican_city
	"🇻🇨",	//flag-vc
	"🇻🇨",	//st_vincent_grenadines
	"🇻🇪",	//flag-ve
	"🇻🇪",	//venezuela
	"🇻🇬",	//flag-vg
	"🇻🇬",	//british_virgin_islands
	"🇻🇮",	//flag-vi
	"🇻🇮",	//us_virgin_islands
	"🇻🇳",	//flag-vn
	"🇻🇳",	//vietnam
	"🇻🇺",	//flag-vu
	"🇻🇺",	//vanuatu
	"🇼🇫",	//flag-wf
	"🇼🇫",	//wallis_futuna
	"🇼🇸",	//flag-ws
	"🇼🇸",	//samoa
	"🇽🇰",	//flag-xk
	"🇽🇰",	//kosovo
	"🇾🇪",	//flag-ye
	"🇾🇪",	//yemen
	"🇾🇹",	//flag-yt
	"🇾🇹",	//mayotte
	"🇿🇦",	//flag-za
	"🇿🇦",	//south_africa
	"🇿🇦",	//za
	"🇿🇲",	//flag-zm
	"🇿🇲",	//zambia
	"🇿🇼",	//flag-zw
	"🇿🇼",	//zimbabwe
	"🏴󠁧󠁢󠁥󠁮󠁧󠁿",	//flag-england
	"🏴󠁧󠁢󠁳󠁣󠁴󠁿",	//flag-scotland
	"🏴󠁧󠁢󠁷󠁬󠁳󠁿",	//flag-wales
	"🎅🏻",	//santa_light_skin_tone
	"🎅🏼",	//santa_medium_light_skin_tone
	"🎅🏽",	//santa_medium_skin_tone
	"🎅🏾",	//santa_medium_dark_skin_tone
	"🎅🏿",	//santa_dark_skin_tone
	"🏂🏻",	//snowboarder_light_skin_tone
	"🏂🏼",	//snowboarder_medium_light_skin_tone
	"🏂🏽",	//snowboarder_medium_skin_tone
	"🏂🏾",	//snowboarder_medium_dark_skin_tone
	"🏂🏿",	//snowboarder_dark_skin_tone
	"🏃🏻‍♀️",	//woman-running_light_skin_tone
	"🏃🏻‍♀️",	//running_woman_light_skin_tone
	"🏃🏼‍♀️",	//woman-running_medium_light_skin_tone
	"🏃🏼‍♀️",	//running_woman_medium_light_skin_tone
	"🏃🏽‍♀️",	//woman-running_medium_skin_tone
	"🏃🏽‍♀️",	//running_woman_medium_skin_tone
	"🏃🏾‍♀️",	//woman-running_medium_dark_skin_tone
	"🏃🏾‍♀️",	//running_woman_medium_dark_skin_tone
	"🏃🏿‍♀️",	//woman-running_dark_skin_tone
	"🏃🏿‍♀️",	//running_woman_dark_skin_tone
	"🏃🏻‍♂️",	//man-running_light_skin_tone
	"🏃🏻‍♂️",	//running_man_light_skin_tone
	"🏃🏼‍♂️",	//man-running_medium_light_skin_tone
	"🏃🏼‍♂️",	//running_man_medium_light_skin_tone
	"🏃🏽‍♂️",	//man-running_medium_skin_tone
	"🏃🏽‍♂️",	//running_man_medium_skin_tone
	"🏃🏾‍♂️",	//man-running_medium_dark_skin_tone
	"🏃🏾‍♂️",	//running_man_medium_dark_skin_tone
	"🏃🏿‍♂️",	//man-running_dark_skin_tone
	"🏃🏿‍♂️",	//running_man_dark_skin_tone
	"🏃🏻",	//runner_light_skin_tone
	"🏃🏻",	//running_light_skin_tone
	"🏃🏼",	//runner_medium_light_skin_tone
	"🏃🏼",	//running_medium_light_skin_tone
	"🏃🏽",	//runner_medium_skin_tone
	"🏃🏽",	//running_medium_skin_tone
	"🏃🏾",	//runner_medium_dark_skin_tone
	"🏃🏾",	//running_medium_dark_skin_tone
	"🏃🏿",	//runner_dark_skin_tone
	"🏃🏿",	//running_dark_skin_tone
	"🏄🏻‍♀️",	//woman-surfing_light_skin_tone
	"🏄🏻‍♀️",	//surfing_woman_light_skin_tone
	"🏄🏼‍♀️",	//woman-surfing_medium_light_skin_tone
	"🏄🏼‍♀️",	//surfing_woman_medium_light_skin_tone
	"🏄🏽‍♀️",	//woman-surfing_medium_skin_tone
	"🏄🏽‍♀️",	//surfing_woman_medium_skin_tone
	"🏄🏾‍♀️",	//woman-surfing_medium_dark_skin_tone
	"🏄🏾‍♀️",	//surfing_woman_medium_dark_skin_tone
	"🏄🏿‍♀️",	//woman-surfing_dark_skin_tone
	"🏄🏿‍♀️",	//surfing_woman_dark_skin_tone
	"🏄🏻‍♂️",	//man-surfing_light_skin_tone
	"🏄🏻‍♂️",	//surfing_man_light_skin_tone
	"🏄🏼‍♂️",	//man-surfing_medium_light_skin_tone
	"🏄🏼‍♂️",	//surfing_man_medium_light_skin_tone
	"🏄🏽‍♂️",	//man-surfing_medium_skin_tone
	"🏄🏽‍♂️",	//surfing_man_medium_skin_tone
	"🏄🏾‍♂️",	//man-surfing_medium_dark_skin_tone
	"🏄🏾‍♂️",	//surfing_man_medium_dark_skin_tone
	"🏄🏿‍♂️",	//man-surfing_dark_skin_tone
	"🏄🏿‍♂️",	//surfing_man_dark_skin_tone
	"🏄🏻",	//surfer_light_skin_tone
	"🏄🏼",	//surfer_medium_light_skin_tone
	"🏄🏽",	//surfer_medium_skin_tone
	"🏄🏾",	//surfer_medium_dark_skin_tone
	"🏄🏿",	//surfer_dark_skin_tone
	"🏇🏻",	//horse_racing_light_skin_tone
	"🏇🏼",	//horse_racing_medium_light_skin_tone
	"🏇🏽",	//horse_racing_medium_skin_tone
	"🏇🏾",	//horse_racing_medium_dark_skin_tone
	"🏇🏿",	//horse_racing_dark_skin_tone
	"🏊🏻‍♀️",	//woman-swimming_light_skin_tone
	"🏊🏻‍♀️",	//swimming_woman_light_skin_tone
	"🏊🏼‍♀️",	//woman-swimming_medium_light_skin_tone
	"🏊🏼‍♀️",	//swimming_woman_medium_light_skin_tone
	"🏊🏽‍♀️",	//woman-swimming_medium_skin_tone
	"🏊🏽‍♀️",	//swimming_woman_medium_skin_tone
	"🏊🏾‍♀️",	//woman-swimming_medium_dark_skin_tone
	"🏊🏾‍♀️",	//swimming_woman_medium_dark_skin_tone
	"🏊🏿‍♀️",	//woman-swimming_dark_skin_tone
	"🏊🏿‍♀️",	//swimming_woman_dark_skin_tone
	"🏊🏻‍♂️",	//man-swimming_light_skin_tone
	"🏊🏻‍♂️",	//swimming_man_light_skin_tone
	"🏊🏼‍♂️",	//man-swimming_medium_light_skin_tone
	"🏊🏼‍♂️",	//swimming_man_medium_light_skin_tone
	"🏊🏽‍♂️",	//man-swimming_medium_skin_tone
	"🏊🏽‍♂️",	//swimming_man_medium_skin_tone
	"🏊🏾‍♂️",	//man-swimming_medium_dark_skin_tone
	"🏊🏾‍♂️",	//swimming_man_medium_dark_skin_tone
	"🏊🏿‍♂️",	//man-swimming_dark_skin_tone
	"🏊🏿‍♂️",	//swimming_man_dark_skin_tone
	"🏊🏻",	//swimmer_light_skin_tone
	"🏊🏼",	//swimmer_medium_light_skin_tone
	"🏊🏽",	//swimmer_medium_skin_tone
	"🏊🏾",	//swimmer_medium_dark_skin_tone
	"🏊🏿",	//swimmer_dark_skin_tone
	"🏋🏻‍♀️",	//woman-lifting-weights_light_skin_tone
	"🏋🏻‍♀️",	//weight_lifting_woman_light_skin_tone
	"🏋🏼‍♀️",	//woman-lifting-weights_medium_light_skin_tone
	"🏋🏼‍♀️",	//weight_lifting_woman_medium_light_skin_tone
	"🏋🏽‍♀️",	//woman-lifting-weights_medium_skin_tone
	"🏋🏽‍♀️",	//weight_lifting_woman_medium_skin_tone
	"🏋🏾‍♀️",	//woman-lifting-weights_medium_dark_skin_tone
	"🏋🏾‍♀️",	//weight_lifting_woman_medium_dark_skin_tone
	"🏋🏿‍♀️",	//woman-lifting-weights_dark_skin_tone
	"🏋🏿‍♀️",	//weight_lifting_woman_dark_skin_tone
	"🏋🏻‍♂️",	//man-lifting-weights_light_skin_tone
	"🏋🏻‍♂️",	//weight_lifting_man_light_skin_tone
	"🏋🏼‍♂️",	//man-lifting-weights_medium_light_skin_tone
	"🏋🏼‍♂️",	//weight_lifting_man_medium_light_skin_tone
	"🏋🏽‍♂️",	//man-lifting-weights_medium_skin_tone
	"🏋🏽‍♂️",	//weight_lifting_man_medium_skin_tone
	"🏋🏾‍♂️",	//man-lifting-weights_medium_dark_skin_tone
	"🏋🏾‍♂️",	//weight_lifting_man_medium_dark_skin_tone
	"🏋🏿‍♂️",	//man-lifting-weights_dark_skin_tone
	"🏋🏿‍♂️",	//weight_lifting_man_dark_skin_tone
	"🏋🏻",	//weight_lifter_light_skin_tone
	"🏋🏼",	//weight_lifter_medium_light_skin_tone
	"🏋🏽",	//weight_lifter_medium_skin_tone
	"🏋🏾",	//weight_lifter_medium_dark_skin_tone
	"🏋🏿",	//weight_lifter_dark_skin_tone
	"🏌🏻‍♀️",	//woman-golfing_light_skin_tone
	"🏌🏻‍♀️",	//golfing_woman_light_skin_tone
	"🏌🏼‍♀️",	//woman-golfing_medium_light_skin_tone
	"🏌🏼‍♀️",	//golfing_woman_medium_light_skin_tone
	"🏌🏽‍♀️",	//woman-golfing_medium_skin_tone
	"🏌🏽‍♀️",	//golfing_woman_medium_skin_tone
	"🏌🏾‍♀️",	//woman-golfing_medium_dark_skin_tone
	"🏌🏾‍♀️",	//golfing_woman_medium_dark_skin_tone
	"🏌🏿‍♀️",	//woman-golfing_dark_skin_tone
	"🏌🏿‍♀️",	//golfing_woman_dark_skin_tone
	"🏌🏻‍♂️",	//man-golfing_light_skin_tone
	"🏌🏻‍♂️",	//golfing_man_light_skin_tone
	"🏌🏼‍♂️",	//man-golfing_medium_light_skin_tone
	"🏌🏼‍♂️",	//golfing_man_medium_light_skin_tone
	"🏌🏽‍♂️",	//man-golfing_medium_skin_tone
	"🏌🏽‍♂️",	//golfing_man_medium_skin_tone
	"🏌🏾‍♂️",	//man-golfing_medium_dark_skin_tone
	"🏌🏾‍♂️",	//golfing_man_medium_dark_skin_tone
	"🏌🏿‍♂️",	//man-golfing_dark_skin_tone
	"🏌🏿‍♂️",	//golfing_man_dark_skin_tone
	"🏌🏻",	//golfer_light_skin_tone
	"🏌🏼",	//golfer_medium_light_skin_tone
	"🏌🏽",	//golfer_medium_skin_tone
	"🏌🏾",	//golfer_medium_dark_skin_tone
	"🏌🏿",	//golfer_dark_skin_tone
	"👂🏻",	//ear_light_skin_tone
	"👂🏼",	//ear_medium_light_skin_tone
	"👂🏽",	//ear_medium_skin_tone
	"👂🏾",	//ear_medium_dark_skin_tone
	"👂🏿",	//ear_dark_skin_tone
	"👃🏻",	//nose_light_skin_tone
	"👃🏼",	//nose_medium_light_skin_tone
	"👃🏽",	//nose_medium_skin_tone
	"👃🏾",	//nose_medium_dark_skin_tone
	"👃🏿",	//nose_dark_skin_tone
	"👆🏻",	//point_up_2_light_skin_tone
	"👆🏼",	//point_up_2_medium_light_skin_tone
	"👆🏽",	//point_up_2_medium_skin_tone
	"👆🏾",	//point_up_2_medium_dark_skin_tone
	"👆🏿",	//point_up_2_dark_skin_tone
	"👇🏻",	//point_down_light_skin_tone
	"👇🏼",	//point_down_medium_light_skin_tone
	"👇🏽",	//point_down_medium_skin_tone
	"👇🏾",	//point_down_medium_dark_skin_tone
	"👇🏿",	//point_down_dark_skin_tone
	"👈🏻",	//point_left_light_skin_tone
	"👈🏼",	//point_left_medium_light_skin_tone
	"👈🏽",	//point_left_medium_skin_tone
	"👈🏾",	//point_left_medium_dark_skin_tone
	"👈🏿",	//point_left_dark_skin_tone
	"👉🏻",	//point_right_light_skin_tone
	"👉🏼",	//point_right_medium_light_skin_tone
	"👉🏽",	//point_right_medium_skin_tone
	"👉🏾",	//point_right_medium_dark_skin_tone
	"👉🏿",	//point_right_dark_skin_tone
	"👊🏻",	//facepunch_light_skin_tone
	"👊🏻",	//punch_light_skin_tone
	"👊🏻",	//fist_oncoming_light_skin_tone
	"👊🏼",	//facepunch_medium_light_skin_tone
	"👊🏼",	//punch_medium_light_skin_tone
	"👊🏼",	//fist_oncoming_medium_light_skin_tone
	"👊🏽",	//facepunch_medium_skin_tone
	"👊🏽",	//punch_medium_skin_tone
	"👊🏽",	//fist_oncoming_medium_skin_tone
	"👊🏾",	//facepunch_medium_dark_skin_tone
	"👊🏾",	//punch_medium_dark_skin_tone
	"👊🏾",	//fist_oncoming_medium_dark_skin_tone
	"👊🏿",	//facepunch_dark_skin_tone
	"👊🏿",	//punch_dark_skin_tone
	"👊🏿",	//fist_oncoming_dark_skin_tone
	"👋🏻",	//wave_light_skin_tone
	"👋🏼",	//wave_medium_light_skin_tone
	"👋🏽",	//wave_medium_skin_tone
	"👋🏾",	//wave_medium_dark_skin_tone
	"👋🏿",	//wave_dark_skin_tone
	"👌🏻",	//ok_hand_light_skin_tone
	"👌🏼",	//ok_hand_medium_light_skin_tone
	"👌🏽",	//ok_hand_medium_skin_tone
	"👌🏾",	//ok_hand_medium_dark_skin_tone
	"👌🏿",	//ok_hand_dark_skin_tone
	"👍🏻",	//+1_light_skin_tone
	"👍🏻",	//thumbsup_light_skin_tone
	"👍🏼",	//+1_medium_light_skin_tone
	"👍🏼",	//thumbsup_medium_light_skin_tone
	"👍🏽",	//+1_medium_skin_tone
	"👍🏽",	//thumbsup_medium_skin_tone
	"👍🏾",	//+1_medium_dark_skin_tone
	"👍🏾",	//thumbsup_medium_dark_skin_tone
	"👍🏿",	//+1_dark_skin_tone
	"👍🏿",	//thumbsup_dark_skin_tone
	"👎🏻",	//-1_light_skin_tone
	"👎🏻",	//thumbsdown_light_skin_tone
	"👎🏼",	//-1_medium_light_skin_tone
	"👎🏼",	//thumbsdown_medium_light_skin_tone
	"👎🏽",	//-1_medium_skin_tone
	"👎🏽",	//thumbsdown_medium_skin_tone
	"👎🏾",	//-1_medium_dark_skin_tone
	"👎🏾",	//thumbsdown_medium_dark_skin_tone
	"👎🏿",	//-1_dark_skin_tone
	"👎🏿",	//thumbsdown_dark_skin_tone
	"👏🏻",	//clap_light_skin_tone
	"👏🏼",	//clap_medium_light_skin_tone
	"👏🏽",	//clap_medium_skin_tone
	"👏🏾",	//clap_medium_dark_skin_tone
	"👏🏿",	//clap_dark_skin_tone
	"👐🏻",	//open_hands_light_skin_tone
	"👐🏼",	//open_hands_medium_light_skin_tone
	"👐🏽",	//open_hands_medium_skin_tone
	"👐🏾",	//open_hands_medium_dark_skin_tone
	"👐🏿",	//open_hands_dark_skin_tone
	"👦🏻",	//boy_light_skin_tone
	"👦🏼",	//boy_medium_light_skin_tone
	"👦🏽",	//boy_medium_skin_tone
	"👦🏾",	//boy_medium_dark_skin_tone
	"👦🏿",	//boy_dark_skin_tone
	"👧🏻",	//girl_light_skin_tone
	"👧🏼",	//girl_medium_light_skin_tone
	"👧🏽",	//girl_medium_skin_tone
	"👧🏾",	//girl_medium_dark_skin_tone
	"👧🏿",	//girl_dark_skin_tone
	"👨🏻‍🌾",	//male-farmer_light_skin_tone
	"👨🏻‍🌾",	//man_farmer_light_skin_tone
	"👨🏼‍🌾",	//male-farmer_medium_light_skin_tone
	"👨🏼‍🌾",	//man_farmer_medium_light_skin_tone
	"👨🏽‍🌾",	//male-farmer_medium_skin_tone
	"👨🏽‍🌾",	//man_farmer_medium_skin_tone
	"👨🏾‍🌾",	//male-farmer_medium_dark_skin_tone
	"👨🏾‍🌾",	//man_farmer_medium_dark_skin_tone
	"👨🏿‍🌾",	//male-farmer_dark_skin_tone
	"👨🏿‍🌾",	//man_farmer_dark_skin_tone
	"👨🏻‍🍳",	//male-cook_light_skin_tone
	"👨🏻‍🍳",	//man_cook_light_skin_tone
	"👨🏼‍🍳",	//male-cook_medium_light_skin_tone
	"👨🏼‍🍳",	//man_cook_medium_light_skin_tone
	"👨🏽‍🍳",	//male-cook_medium_skin_tone
	"👨🏽‍🍳",	//man_cook_medium_skin_tone
	"👨🏾‍🍳",	//male-cook_medium_dark_skin_tone
	"👨🏾‍🍳",	//man_cook_medium_dark_skin_tone
	"👨🏿‍🍳",	//male-cook_dark_skin_tone
	"👨🏿‍🍳",	//man_cook_dark_skin_tone
	"👨🏻‍🍼",	//man_feeding_baby_light_skin_tone
	"👨🏼‍🍼",	//man_feeding_baby_medium_light_skin_tone
	"👨🏽‍🍼",	//man_feeding_baby_medium_skin_tone
	"👨🏾‍🍼",	//man_feeding_baby_medium_dark_skin_tone
	"👨🏿‍🍼",	//man_feeding_baby_dark_skin_tone
	"👨🏻‍🎓",	//male-student_light_skin_tone
	"👨🏻‍🎓",	//man_student_light_skin_tone
	"👨🏼‍🎓",	//male-student_medium_light_skin_tone
	"👨🏼‍🎓",	//man_student_medium_light_skin_tone
	"👨🏽‍🎓",	//male-student_medium_skin_tone
	"👨🏽‍🎓",	//man_student_medium_skin_tone
	"👨🏾‍🎓",	//male-student_medium_dark_skin_tone
	"👨🏾‍🎓",	//man_student_medium_dark_skin_tone
	"👨🏿‍🎓",	//male-student_dark_skin_tone
	"👨🏿‍🎓",	//man_student_dark_skin_tone
	"👨🏻‍🎤",	//male-singer_light_skin_tone
	"👨🏻‍🎤",	//man_singer_light_skin_tone
	"👨🏼‍🎤",	//male-singer_medium_light_skin_tone
	"👨🏼‍🎤",	//man_singer_medium_light_skin_tone
	"👨🏽‍🎤",	//male-singer_medium_skin_tone
	"👨🏽‍🎤",	//man_singer_medium_skin_tone
	"👨🏾‍🎤",	//male-singer_medium_dark_skin_tone
	"👨🏾‍🎤",	//man_singer_medium_dark_skin_tone
	"👨🏿‍🎤",	//male-singer_dark_skin_tone
	"👨🏿‍🎤",	//man_singer_dark_skin_tone
	"👨🏻‍🎨",	//male-artist_light_skin_tone
	"👨🏻‍🎨",	//man_artist_light_skin_tone
	"👨🏼‍🎨",	//male-artist_medium_light_skin_tone
	"👨🏼‍🎨",	//man_artist_medium_light_skin_tone
	"👨🏽‍🎨",	//male-artist_medium_skin_tone
	"👨🏽‍🎨",	//man_artist_medium_skin_tone
	"👨🏾‍🎨",	//male-artist_medium_dark_skin_tone
	"👨🏾‍🎨",	//man_artist_medium_dark_skin_tone
	"👨🏿‍🎨",	//male-artist_dark_skin_tone
	"👨🏿‍🎨",	//man_artist_dark_skin_tone
	"👨🏻‍🏫",	//male-teacher_light_skin_tone
	"👨🏻‍🏫",	//man_teacher_light_skin_tone
	"👨🏼‍🏫",	//male-teacher_medium_light_skin_tone
	"👨🏼‍🏫",	//man_teacher_medium_light_skin_tone
	"👨🏽‍🏫",	//male-teacher_medium_skin_tone
	"👨🏽‍🏫",	//man_teacher_medium_skin_tone
	"👨🏾‍🏫",	//male-teacher_medium_dark_skin_tone
	"👨🏾‍🏫",	//man_teacher_medium_dark_skin_tone
	"👨🏿‍🏫",	//male-teacher_dark_skin_tone
	"👨🏿‍🏫",	//man_teacher_dark_skin_tone
	"👨🏻‍🏭",	//male-factory-worker_light_skin_tone
	"👨🏻‍🏭",	//man_factory_worker_light_skin_tone
	"👨🏼‍🏭",	//male-factory-worker_medium_light_skin_tone
	"👨🏼‍🏭",	//man_factory_worker_medium_light_skin_tone
	"👨🏽‍🏭",	//male-factory-worker_medium_skin_tone
	"👨🏽‍🏭",	//man_factory_worker_medium_skin_tone
	"👨🏾‍🏭",	//male-factory-worker_medium_dark_skin_tone
	"👨🏾‍🏭",	//man_factory_worker_medium_dark_skin_tone
	"👨🏿‍🏭",	//male-factory-worker_dark_skin_tone
	"👨🏿‍🏭",	//man_factory_worker_dark_skin_tone
	"👨🏻‍💻",	//male-technologist_light_skin_tone
	"👨🏻‍💻",	//man_technologist_light_skin_tone
	"👨🏼‍💻",	//male-technologist_medium_light_skin_tone
	"👨🏼‍💻",	//man_technologist_medium_light_skin_tone
	"👨🏽‍💻",	//male-technologist_medium_skin_tone
	"👨🏽‍💻",	//man_technologist_medium_skin_tone
	"👨🏾‍💻",	//male-technologist_medium_dark_skin_tone
	"👨🏾‍💻",	//man_technologist_medium_dark_skin_tone
	"👨🏿‍💻",	//male-technologist_dark_skin_tone
	"👨🏿‍💻",	//man_technologist_dark_skin_tone
	"👨🏻‍💼",	//male-office-worker_light_skin_tone
	"👨🏻‍💼",	//man_office_worker_light_skin_tone
	"👨🏼‍💼",	//male-office-worker_medium_light_skin_tone
	"👨🏼‍💼",	//man_office_worker_medium_light_skin_tone
	"👨🏽‍💼",	//male-office-worker_medium_skin_tone
	"👨🏽‍💼",	//man_office_worker_medium_skin_tone
	"👨🏾‍💼",	//male-office-worker_medium_dark_skin_tone
	"👨🏾‍💼",	//man_office_worker_medium_dark_skin_tone
	"👨🏿‍💼",	//male-office-worker_dark_skin_tone
	"👨🏿‍💼",	//man_office_worker_dark_skin_tone
	"👨🏻‍🔧",	//male-mechanic_light_skin_tone
	"👨🏻‍🔧",	//man_mechanic_light_skin_tone
	"👨🏼‍🔧",	//male-mechanic_medium_light_skin_tone
	"👨🏼‍🔧",	//man_mechanic_medium_light_skin_tone
	"👨🏽‍🔧",	//male-mechanic_medium_skin_tone
	"👨🏽‍🔧",	//man_mechanic_medium_skin_tone
	"👨🏾‍🔧",	//male-mechanic_medium_dark_skin_tone
	"👨🏾‍🔧",	//man_mechanic_medium_dark_skin_tone
	"👨🏿‍🔧",	//male-mechanic_dark_skin_tone
	"👨🏿‍🔧",	//man_mechanic_dark_skin_tone
	"👨🏻‍🔬",	//male-scientist_light_skin_tone
	"👨🏻‍🔬",	//man_scientist_light_skin_tone
	"👨🏼‍🔬",	//male-scientist_medium_light_skin_tone
	"👨🏼‍🔬",	//man_scientist_medium_light_skin_tone
	"👨🏽‍🔬",	//male-scientist_medium_skin_tone
	"👨🏽‍🔬",	//man_scientist_medium_skin_tone
	"👨🏾‍🔬",	//male-scientist_medium_dark_skin_tone
	"👨🏾‍🔬",	//man_scientist_medium_dark_skin_tone
	"👨🏿‍🔬",	//male-scientist_dark_skin_tone
	"👨🏿‍🔬",	//man_scientist_dark_skin_tone
	"👨🏻‍🚀",	//male-astronaut_light_skin_tone
	"👨🏻‍🚀",	//man_astronaut_light_skin_tone
	"👨🏼‍🚀",	//male-astronaut_medium_light_skin_tone
	"👨🏼‍🚀",	//man_astronaut_medium_light_skin_tone
	"👨🏽‍🚀",	//male-astronaut_medium_skin_tone
	"👨🏽‍🚀",	//man_astronaut_medium_skin_tone
	"👨🏾‍🚀",	//male-astronaut_medium_dark_skin_tone
	"👨🏾‍🚀",	//man_astronaut_medium_dark_skin_tone
	"👨🏿‍🚀",	//male-astronaut_dark_skin_tone
	"👨🏿‍🚀",	//man_astronaut_dark_skin_tone
	"👨🏻‍🚒",	//male-firefighter_light_skin_tone
	"👨🏻‍🚒",	//man_firefighter_light_skin_tone
	"👨🏼‍🚒",	//male-firefighter_medium_light_skin_tone
	"👨🏼‍🚒",	//man_firefighter_medium_light_skin_tone
	"👨🏽‍🚒",	//male-firefighter_medium_skin_tone
	"👨🏽‍🚒",	//man_firefighter_medium_skin_tone
	"👨🏾‍🚒",	//male-firefighter_medium_dark_skin_tone
	"👨🏾‍🚒",	//man_firefighter_medium_dark_skin_tone
	"👨🏿‍🚒",	//male-firefighter_dark_skin_tone
	"👨🏿‍🚒",	//man_firefighter_dark_skin_tone
	"👨🏻‍🦯",	//man_with_probing_cane_light_skin_tone
	"👨🏼‍🦯",	//man_with_probing_cane_medium_light_skin_tone
	"👨🏽‍🦯",	//man_with_probing_cane_medium_skin_tone
	"👨🏾‍🦯",	//man_with_probing_cane_medium_dark_skin_tone
	"👨🏿‍🦯",	//man_with_probing_cane_dark_skin_tone
	"👨🏻‍🦰",	//red_haired_man_light_skin_tone
	"👨🏼‍🦰",	//red_haired_man_medium_light_skin_tone
	"👨🏽‍🦰",	//red_haired_man_medium_skin_tone
	"👨🏾‍🦰",	//red_haired_man_medium_dark_skin_tone
	"👨🏿‍🦰",	//red_haired_man_dark_skin_tone
	"👨🏻‍🦱",	//curly_haired_man_light_skin_tone
	"👨🏼‍🦱",	//curly_haired_man_medium_light_skin_tone
	"👨🏽‍🦱",	//curly_haired_man_medium_skin_tone
	"👨🏾‍🦱",	//curly_haired_man_medium_dark_skin_tone
	"👨🏿‍🦱",	//curly_haired_man_dark_skin_tone
	"👨🏻‍🦲",	//bald_man_light_skin_tone
	"👨🏼‍🦲",	//bald_man_medium_light_skin_tone
	"👨🏽‍🦲",	//bald_man_medium_skin_tone
	"👨🏾‍🦲",	//bald_man_medium_dark_skin_tone
	"👨🏿‍🦲",	//bald_man_dark_skin_tone
	"👨🏻‍🦳",	//white_haired_man_light_skin_tone
	"👨🏼‍🦳",	//white_haired_man_medium_light_skin_tone
	"👨🏽‍🦳",	//white_haired_man_medium_skin_tone
	"👨🏾‍🦳",	//white_haired_man_medium_dark_skin_tone
	"👨🏿‍🦳",	//white_haired_man_dark_skin_tone
	"👨🏻‍🦼",	//man_in_motorized_wheelchair_light_skin_tone
	"👨🏼‍🦼",	//man_in_motorized_wheelchair_medium_light_skin_tone
	"👨🏽‍🦼",	//man_in_motorized_wheelchair_medium_skin_tone
	"👨🏾‍🦼",	//man_in_motorized_wheelchair_medium_dark_skin_tone
	"👨🏿‍🦼",	//man_in_motorized_wheelchair_dark_skin_tone
	"👨🏻‍🦽",	//man_in_manual_wheelchair_light_skin_tone
	"👨🏼‍🦽",	//man_in_manual_wheelchair_medium_light_skin_tone
	"👨🏽‍🦽",	//man_in_manual_wheelchair_medium_skin_tone
	"👨🏾‍🦽",	//man_in_manual_wheelchair_medium_dark_skin_tone
	"👨🏿‍🦽",	//man_in_manual_wheelchair_dark_skin_tone
	"👨🏻‍⚕️",	//male-doctor_light_skin_tone
	"👨🏻‍⚕️",	//man_health_worker_light_skin_tone
	"👨🏼‍⚕️",	//male-doctor_medium_light_skin_tone
	"👨🏼‍⚕️",	//man_health_worker_medium_light_skin_tone
	"👨🏽‍⚕️",	//male-doctor_medium_skin_tone
	"👨🏽‍⚕️",	//man_health_worker_medium_skin_tone
	"👨🏾‍⚕️",	//male-doctor_medium_dark_skin_tone
	"👨🏾‍⚕️",	//man_health_worker_medium_dark_skin_tone
	"👨🏿‍⚕️",	//male-doctor_dark_skin_tone
	"👨🏿‍⚕️",	//man_health_worker_dark_skin_tone
	"👨🏻‍⚖️",	//male-judge_light_skin_tone
	"👨🏻‍⚖️",	//man_judge_light_skin_tone
	"👨🏼‍⚖️",	//male-judge_medium_light_skin_tone
	"👨🏼‍⚖️",	//man_judge_medium_light_skin_tone
	"👨🏽‍⚖️",	//male-judge_medium_skin_tone
	"👨🏽‍⚖️",	//man_judge_medium_skin_tone
	"👨🏾‍⚖️",	//male-judge_medium_dark_skin_tone
	"👨🏾‍⚖️",	//man_judge_medium_dark_skin_tone
	"👨🏿‍⚖️",	//male-judge_dark_skin_tone
	"👨🏿‍⚖️",	//man_judge_dark_skin_tone
	"👨🏻‍✈️",	//male-pilot_light_skin_tone
	"👨🏻‍✈️",	//man_pilot_light_skin_tone
	"👨🏼‍✈️",	//male-pilot_medium_light_skin_tone
	"👨🏼‍✈️",	//man_pilot_medium_light_skin_tone
	"👨🏽‍✈️",	//male-pilot_medium_skin_tone
	"👨🏽‍✈️",	//man_pilot_medium_skin_tone
	"👨🏾‍✈️",	//male-pilot_medium_dark_skin_tone
	"👨🏾‍✈️",	//man_pilot_medium_dark_skin_tone
	"👨🏿‍✈️",	//male-pilot_dark_skin_tone
	"👨🏿‍✈️",	//man_pilot_dark_skin_tone
	"👨🏻",	//man_light_skin_tone
	"👨🏼",	//man_medium_light_skin_tone
	"👨🏽",	//man_medium_skin_tone
	"👨🏾",	//man_medium_dark_skin_tone
	"👨🏿",	//man_dark_skin_tone
	"👩🏻‍🌾",	//female-farmer_light_skin_tone
	"👩🏻‍🌾",	//woman_farmer_light_skin_tone
	"👩🏼‍🌾",	//female-farmer_medium_light_skin_tone
	"👩🏼‍🌾",	//woman_farmer_medium_light_skin_tone
	"👩🏽‍🌾",	//female-farmer_medium_skin_tone
	"👩🏽‍🌾",	//woman_farmer_medium_skin_tone
	"👩🏾‍🌾",	//female-farmer_medium_dark_skin_tone
	"👩🏾‍🌾",	//woman_farmer_medium_dark_skin_tone
	"👩🏿‍🌾",	//female-farmer_dark_skin_tone
	"👩🏿‍🌾",	//woman_farmer_dark_skin_tone
	"👩🏻‍🍳",	//female-cook_light_skin_tone
	"👩🏻‍🍳",	//woman_cook_light_skin_tone
	"👩🏼‍🍳",	//female-cook_medium_light_skin_tone
	"👩🏼‍🍳",	//woman_cook_medium_light_skin_tone
	"👩🏽‍🍳",	//female-cook_medium_skin_tone
	"👩🏽‍🍳",	//woman_cook_medium_skin_tone
	"👩🏾‍🍳",	//female-cook_medium_dark_skin_tone
	"👩🏾‍🍳",	//woman_cook_medium_dark_skin_tone
	"👩🏿‍🍳",	//female-cook_dark_skin_tone
	"👩🏿‍🍳",	//woman_cook_dark_skin_tone
	"👩🏻‍🍼",	//woman_feeding_baby_light_skin_tone
	"👩🏼‍🍼",	//woman_feeding_baby_medium_light_skin_tone
	"👩🏽‍🍼",	//woman_feeding_baby_medium_skin_tone
	"👩🏾‍🍼",	//woman_feeding_baby_medium_dark_skin_tone
	"👩🏿‍🍼",	//woman_feeding_baby_dark_skin_tone
	"👩🏻‍🎓",	//female-student_light_skin_tone
	"👩🏻‍🎓",	//woman_student_light_skin_tone
	"👩🏼‍🎓",	//female-student_medium_light_skin_tone
	"👩🏼‍🎓",	//woman_student_medium_light_skin_tone
	"👩🏽‍🎓",	//female-student_medium_skin_tone
	"👩🏽‍🎓",	//woman_student_medium_skin_tone
	"👩🏾‍🎓",	//female-student_medium_dark_skin_tone
	"👩🏾‍🎓",	//woman_student_medium_dark_skin_tone
	"👩🏿‍🎓",	//female-student_dark_skin_tone
	"👩🏿‍🎓",	//woman_student_dark_skin_tone
	"👩🏻‍🎤",	//female-singer_light_skin_tone
	"👩🏻‍🎤",	//woman_singer_light_skin_tone
	"👩🏼‍🎤",	//female-singer_medium_light_skin_tone
	"👩🏼‍🎤",	//woman_singer_medium_light_skin_tone
	"👩🏽‍🎤",	//female-singer_medium_skin_tone
	"👩🏽‍🎤",	//woman_singer_medium_skin_tone
	"👩🏾‍🎤",	//female-singer_medium_dark_skin_tone
	"👩🏾‍🎤",	//woman_singer_medium_dark_skin_tone
	"👩🏿‍🎤",	//female-singer_dark_skin_tone
	"👩🏿‍🎤",	//woman_singer_dark_skin_tone
	"👩🏻‍🎨",	//female-artist_light_skin_tone
	"👩🏻‍🎨",	//woman_artist_light_skin_tone
	"👩🏼‍🎨",	//female-artist_medium_light_skin_tone
	"👩🏼‍🎨",	//woman_artist_medium_light_skin_tone
	"👩🏽‍🎨",	//female-artist_medium_skin_tone
	"👩🏽‍🎨",	//woman_artist_medium_skin_tone
	"👩🏾‍🎨",	//female-artist_medium_dark_skin_tone
	"👩🏾‍🎨",	//woman_artist_medium_dark_skin_tone
	"👩🏿‍🎨",	//female-artist_dark_skin_tone
	"👩🏿‍🎨",	//woman_artist_dark_skin_tone
	"👩🏻‍🏫",	//female-teacher_light_skin_tone
	"👩🏻‍🏫",	//woman_teacher_light_skin_tone
	"👩🏼‍🏫",	//female-teacher_medium_light_skin_tone
	"👩🏼‍🏫",	//woman_teacher_medium_light_skin_tone
	"👩🏽‍🏫",	//female-teacher_medium_skin_tone
	"👩🏽‍🏫",	//woman_teacher_medium_skin_tone
	"👩🏾‍🏫",	//female-teacher_medium_dark_skin_tone
	"👩🏾‍🏫",	//woman_teacher_medium_dark_skin_tone
	"👩🏿‍🏫",	//female-teacher_dark_skin_tone
	"👩🏿‍🏫",	//woman_teacher_dark_skin_tone
	"👩🏻‍🏭",	//female-factory-worker_light_skin_tone
	"👩🏻‍🏭",	//woman_factory_worker_light_skin_tone
	"👩🏼‍🏭",	//female-factory-worker_medium_light_skin_tone
	"👩🏼‍🏭",	//woman_factory_worker_medium_light_skin_tone
	"👩🏽‍🏭",	//female-factory-worker_medium_skin_tone
	"👩🏽‍🏭",	//woman_factory_worker_medium_skin_tone
	"👩🏾‍🏭",	//female-factory-worker_medium_dark_skin_tone
	"👩🏾‍🏭",	//woman_factory_worker_medium_dark_skin_tone
	"👩🏿‍🏭",	//female-factory-worker_dark_skin_tone
	"👩🏿‍🏭",	//woman_factory_worker_dark_skin_tone
	"👩🏻‍💻",	//female-technologist_light_skin_tone
	"👩🏻‍💻",	//woman_technologist_light_skin_tone
	"👩🏼‍💻",	//female-technologist_medium_light_skin_tone
	"👩🏼‍💻",	//woman_technologist_medium_light_skin_tone
	"👩🏽‍💻",	//female-technologist_medium_skin_tone
	"👩🏽‍💻",	//woman_technologist_medium_skin_tone
	"👩🏾‍💻",	//female-technologist_medium_dark_skin_tone
	"👩🏾‍💻",	//woman_technologist_medium_dark_skin_tone
	"👩🏿‍💻",	//female-technologist_dark_skin_tone
	"👩🏿‍💻",	//woman_technologist_dark_skin_tone
	"👩🏻‍💼",	//female-office-worker_light_skin_tone
	"👩🏻‍💼",	//woman_office_worker_light_skin_tone
	"👩🏼‍💼",	//female-office-worker_medium_light_skin_tone
	"👩🏼‍💼",	//woman_office_worker_medium_light_skin_tone
	"👩🏽‍💼",	//female-office-worker_medium_skin_tone
	"👩🏽‍💼",	//woman_office_worker_medium_skin_tone
	"👩🏾‍💼",	//female-office-worker_medium_dark_skin_tone
	"👩🏾‍💼",	//woman_office_worker_medium_dark_skin_tone
	"👩🏿‍💼",	//female-office-worker_dark_skin_tone
	"👩🏿‍💼",	//woman_office_worker_dark_skin_tone
	"👩🏻‍🔧",	//female-mechanic_light_skin_tone
	"👩🏻‍🔧",	//woman_mechanic_light_skin_tone
	"👩🏼‍🔧",	//female-mechanic_medium_light_skin_tone
	"👩🏼‍🔧",	//woman_mechanic_medium_light_skin_tone
	"👩🏽‍🔧",	//female-mechanic_medium_skin_tone
	"👩🏽‍🔧",	//woman_mechanic_medium_skin_tone
	"👩🏾‍🔧",	//female-mechanic_medium_dark_skin_tone
	"👩🏾‍🔧",	//woman_mechanic_medium_dark_skin_tone
	"👩🏿‍🔧",	//female-mechanic_dark_skin_tone
	"👩🏿‍🔧",	//woman_mechanic_dark_skin_tone
	"👩🏻‍🔬",	//female-scientist_light_skin_tone
	"👩🏻‍🔬",	//woman_scientist_light_skin_tone
	"👩🏼‍🔬",	//female-scientist_medium_light_skin_tone
	"👩🏼‍🔬",	//woman_scientist_medium_light_skin_tone
	"👩🏽‍🔬",	//female-scientist_medium_skin_tone
	"👩🏽‍🔬",	//woman_scientist_medium_skin_tone
	"👩🏾‍🔬",	//female-scientist_medium_dark_skin_tone
	"👩🏾‍🔬",	//woman_scientist_medium_dark_skin_tone
	"👩🏿‍🔬",	//female-scientist_dark_skin_tone
	"👩🏿‍🔬",	//woman_scientist_dark_skin_tone
	"👩🏻‍🚀",	//female-astronaut_light_skin_tone
	"👩🏻‍🚀",	//woman_astronaut_light_skin_tone
	"👩🏼‍🚀",	//female-astronaut_medium_light_skin_tone
	"👩🏼‍🚀",	//woman_astronaut_medium_light_skin_tone
	"👩🏽‍🚀",	//female-astronaut_medium_skin_tone
	"👩🏽‍🚀",	//woman_astronaut_medium_skin_tone
	"👩🏾‍🚀",	//female-astronaut_medium_dark_skin_tone
	"👩🏾‍🚀",	//woman_astronaut_medium_dark_skin_tone
	"👩🏿‍🚀",	//female-astronaut_dark_skin_tone
	"👩🏿‍🚀",	//woman_astronaut_dark_skin_tone
	"👩🏻‍🚒",	//female-firefighter_light_skin_tone
	"👩🏻‍🚒",	//woman_firefighter_light_skin_tone
	"👩🏼‍🚒",	//female-firefighter_medium_light_skin_tone
	"👩🏼‍🚒",	//woman_firefighter_medium_light_skin_tone
	"👩🏽‍🚒",	//female-firefighter_medium_skin_tone
	"👩🏽‍🚒",	//woman_firefighter_medium_skin_tone
	"👩🏾‍🚒",	//female-firefighter_medium_dark_skin_tone
	"👩🏾‍🚒",	//woman_firefighter_medium_dark_skin_tone
	"👩🏿‍🚒",	//female-firefighter_dark_skin_tone
	"👩🏿‍🚒",	//woman_firefighter_dark_skin_tone
	"👩🏻‍🦯",	//woman_with_probing_cane_light_skin_tone
	"👩🏼‍🦯",	//woman_with_probing_cane_medium_light_skin_tone
	"👩🏽‍🦯",	//woman_with_probing_cane_medium_skin_tone
	"👩🏾‍🦯",	//woman_with_probing_cane_medium_dark_skin_tone
	"👩🏿‍🦯",	//woman_with_probing_cane_dark_skin_tone
	"👩🏻‍🦰",	//red_haired_woman_light_skin_tone
	"👩🏼‍🦰",	//red_haired_woman_medium_light_skin_tone
	"👩🏽‍🦰",	//red_haired_woman_medium_skin_tone
	"👩🏾‍🦰",	//red_haired_woman_medium_dark_skin_tone
	"👩🏿‍🦰",	//red_haired_woman_dark_skin_tone
	"👩🏻‍🦱",	//curly_haired_woman_light_skin_tone
	"👩🏼‍🦱",	//curly_haired_woman_medium_light_skin_tone
	"👩🏽‍🦱",	//curly_haired_woman_medium_skin_tone
	"👩🏾‍🦱",	//curly_haired_woman_medium_dark_skin_tone
	"👩🏿‍🦱",	//curly_haired_woman_dark_skin_tone
	"👩🏻‍🦲",	//bald_woman_light_skin_tone
	"👩🏼‍🦲",	//bald_woman_medium_light_skin_tone
	"👩🏽‍🦲",	//bald_woman_medium_skin_tone
	"👩🏾‍🦲",	//bald_woman_medium_dark_skin_tone
	"👩🏿‍🦲",	//bald_woman_dark_skin_tone
	"👩🏻‍🦳",	//white_haired_woman_light_skin_tone
	"👩🏼‍🦳",	//white_haired_woman_medium_light_skin_tone
	"👩🏽‍🦳",	//white_haired_woman_medium_skin_tone
	"👩🏾‍🦳",	//white_haired_woman_medium_dark_skin_tone
	"👩🏿‍🦳",	//white_haired_woman_dark_skin_tone
	"👩🏻‍🦼",	//woman_in_motorized_wheelchair_light_skin_tone
	"👩🏼‍🦼",	//woman_in_motorized_wheelchair_medium_light_skin_tone
	"👩🏽‍🦼",	//woman_in_motorized_wheelchair_medium_skin_tone
	"👩🏾‍🦼",	//woman_in_motorized_wheelchair_medium_dark_skin_tone
	"👩🏿‍🦼",	//woman_in_motorized_wheelchair_dark_skin_tone
	"👩🏻‍🦽",	//woman_in_manual_wheelchair_light_skin_tone
	"👩🏼‍🦽",	//woman_in_manual_wheelchair_medium_light_skin_tone
	"👩🏽‍🦽",	//woman_in_manual_wheelchair_medium_skin_tone
	"👩🏾‍🦽",	//woman_in_manual_wheelchair_medium_dark_skin_tone
	"👩🏿‍🦽",	//woman_in_manual_wheelchair_dark_skin_tone
	"👩🏻‍⚕️",	//female-doctor_light_skin_tone
	"👩🏻‍⚕️",	//woman_health_worker_light_skin_tone
	"👩🏼‍⚕️",	//female-doctor_medium_light_skin_tone
	"👩🏼‍⚕️",	//woman_health_worker_medium_light_skin_tone
	"👩🏽‍⚕️",	//female-doctor_medium_skin_tone
	"👩🏽‍⚕️",	//woman_health_worker_medium_skin_tone
	"👩🏾‍⚕️",	//female-doctor_medium_dark_skin_tone
	"👩🏾‍⚕️",	//woman_health_worker_medium_dark_skin_tone
	"👩🏿‍⚕️",	//female-doctor_dark_skin_tone
	"👩🏿‍⚕️",	//woman_health_worker_dark_skin_tone
	"👩🏻‍⚖️",	//female-judge_light_skin_tone
	"👩🏻‍⚖️",	//woman_judge_light_skin_tone
	"👩🏼‍⚖️",	//female-judge_medium_light_skin_tone
	"👩🏼‍⚖️",	//woman_judge_medium_light_skin_tone
	"👩🏽‍⚖️",	//female-judge_medium_skin_tone
	"👩🏽‍⚖️",	//woman_judge_medium_skin_tone
	"👩🏾‍⚖️",	//female-judge_medium_dark_skin_tone
	"👩🏾‍⚖️",	//woman_judge_medium_dark_skin_tone
	"👩🏿‍⚖️",	//female-judge_dark_skin_tone
	"👩🏿‍⚖️",	//woman_judge_dark_skin_tone
	"👩🏻‍✈️",	//female-pilot_light_skin_tone
	"👩🏻‍✈️",	//woman_pilot_light_skin_tone
	"👩🏼‍✈️",	//female-pilot_medium_light_skin_tone
	"👩🏼‍✈️",	//woman_pilot_medium_light_skin_tone
	"👩🏽‍✈️",	//female-pilot_medium_skin_tone
	"👩🏽‍✈️",	//woman_pilot_medium_skin_tone
	"👩🏾‍✈️",	//female-pilot_medium_dark_skin_tone
	"👩🏾‍✈️",	//woman_pilot_medium_dark_skin_tone
	"👩🏿‍✈️",	//female-pilot_dark_skin_tone
	"👩🏿‍✈️",	//woman_pilot_dark_skin_tone
	"👩🏻",	//woman_light_skin_tone
	"👩🏼",	//woman_medium_light_skin_tone
	"👩🏽",	//woman_medium_skin_tone
	"👩🏾",	//woman_medium_dark_skin_tone
	"👩🏿",	//woman_dark_skin_tone
	"👫🏻",	//man_and_woman_holding_hands_light_skin_tone
	"👫🏻",	//woman_and_man_holding_hands_light_skin_tone
	"👫🏻",	//couple_light_skin_tone
	"👫🏼",	//man_and_woman_holding_hands_medium_light_skin_tone
	"👫🏼",	//woman_and_man_holding_hands_medium_light_skin_tone
	"👫🏼",	//couple_medium_light_skin_tone
	"👫🏽",	//man_and_woman_holding_hands_medium_skin_tone
	"👫🏽",	//woman_and_man_holding_hands_medium_skin_tone
	"👫🏽",	//couple_medium_skin_tone
	"👫🏾",	//man_and_woman_holding_hands_medium_dark_skin_tone
	"👫🏾",	//woman_and_man_holding_hands_medium_dark_skin_tone
	"👫🏾",	//couple_medium_dark_skin_tone
	"👫🏿",	//man_and_woman_holding_hands_dark_skin_tone
	"👫🏿",	//woman_and_man_holding_hands_dark_skin_tone
	"👫🏿",	//couple_dark_skin_tone
	"👩🏻‍🤝‍👨🏼",	//man_and_woman_holding_hands_light_skin_tone_medium_light_skin_tone
	"👩🏻‍🤝‍👨🏼",	//woman_and_man_holding_hands_light_skin_tone_medium_light_skin_tone
	"👩🏻‍🤝‍👨🏼",	//couple_light_skin_tone_medium_light_skin_tone
	"👩🏻‍🤝‍👨🏽",	//man_and_woman_holding_hands_light_skin_tone_medium_skin_tone
	"👩🏻‍🤝‍👨🏽",	//woman_and_man_holding_hands_light_skin_tone_medium_skin_tone
	"👩🏻‍🤝‍👨🏽",	//couple_light_skin_tone_medium_skin_tone
	"👩🏻‍🤝‍👨🏾",	//man_and_woman_holding_hands_light_skin_tone_medium_dark_skin_tone
	"👩🏻‍🤝‍👨🏾",	//woman_and_man_holding_hands_light_skin_tone_medium_dark_skin_tone
	"👩🏻‍🤝‍👨🏾",	//couple_light_skin_tone_medium_dark_skin_tone
	"👩🏻‍🤝‍👨🏿",	//man_and_woman_holding_hands_light_skin_tone_dark_skin_tone
	"👩🏻‍🤝‍👨🏿",	//woman_and_man_holding_hands_light_skin_tone_dark_skin_tone
	"👩🏻‍🤝‍👨🏿",	//couple_light_skin_tone_dark_skin_tone
	"👩🏼‍🤝‍👨🏻",	//man_and_woman_holding_hands_medium_light_skin_tone_light_skin_tone
	"👩🏼‍🤝‍👨🏻",	//woman_and_man_holding_hands_medium_light_skin_tone_light_skin_tone
	"👩🏼‍🤝‍👨🏻",	//couple_medium_light_skin_tone_light_skin_tone
	"👩🏼‍🤝‍👨🏽",	//man_and_woman_holding_hands_medium_light_skin_tone_medium_skin_tone
	"👩🏼‍🤝‍👨🏽",	//woman_and_man_holding_hands_medium_light_skin_tone_medium_skin_tone
	"👩🏼‍🤝‍👨🏽",	//couple_medium_light_skin_tone_medium_skin_tone
	"👩🏼‍🤝‍👨🏾",	//man_and_woman_holding_hands_medium_light_skin_tone_medium_dark_skin_tone
	"👩🏼‍🤝‍👨🏾",	//woman_and_man_holding_hands_medium_light_skin_tone_medium_dark_skin_tone
	"👩🏼‍🤝‍👨🏾",	//couple_medium_light_skin_tone_medium_dark_skin_tone
	"👩🏼‍🤝‍👨🏿",	//man_and_woman_holding_hands_medium_light_skin_tone_dark_skin_tone
	"👩🏼‍🤝‍👨🏿",	//woman_and_man_holding_hands_medium_light_skin_tone_dark_skin_tone
	"👩🏼‍🤝‍👨🏿",	//couple_medium_light_skin_tone_dark_skin_tone
	"👩🏽‍🤝‍👨🏻",	//man_and_woman_holding_hands_medium_skin_tone_light_skin_tone
	"👩🏽‍🤝‍👨🏻",	//woman_and_man_holding_hands_medium_skin_tone_light_skin_tone
	"👩🏽‍🤝‍👨🏻",	//couple_medium_skin_tone_light_skin_tone
	"👩🏽‍🤝‍👨🏼",	//man_and_woman_holding_hands_medium_skin_tone_medium_light_skin_tone
	"👩🏽‍🤝‍👨🏼",	//woman_and_man_holding_hands_medium_skin_tone_medium_light_skin_tone
	"👩🏽‍🤝‍👨🏼",	//couple_medium_skin_tone_medium_light_skin_tone
	"👩🏽‍🤝‍👨🏾",	//man_and_woman_holding_hands_medium_skin_tone_medium_dark_skin_tone
	"👩🏽‍🤝‍👨🏾",	//woman_and_man_holding_hands_medium_skin_tone_medium_dark_skin_tone
	"👩🏽‍🤝‍👨🏾",	//couple_medium_skin_tone_medium_dark_skin_tone
	"👩🏽‍🤝‍👨🏿",	//man_and_woman_holding_hands_medium_skin_tone_dark_skin_tone
	"👩🏽‍🤝‍👨🏿",	//woman_and_man_holding_hands_medium_skin_tone_dark_skin_tone
	"👩🏽‍🤝‍👨🏿",	//couple_medium_skin_tone_dark_skin_tone
	"👩🏾‍🤝‍👨🏻",	//man_and_woman_holding_hands_medium_dark_skin_tone_light_skin_tone
	"👩🏾‍🤝‍👨🏻",	//woman_and_man_holding_hands_medium_dark_skin_tone_light_skin_tone
	"👩🏾‍🤝‍👨🏻",	//couple_medium_dark_skin_tone_light_skin_tone
	"👩🏾‍🤝‍👨🏼",	//man_and_woman_holding_hands_medium_dark_skin_tone_medium_light_skin_tone
	"👩🏾‍🤝‍👨🏼",	//woman_and_man_holding_hands_medium_dark_skin_tone_medium_light_skin_tone
	"👩🏾‍🤝‍👨🏼",	//couple_medium_dark_skin_tone_medium_light_skin_tone
	"👩🏾‍🤝‍👨🏽",	//man_and_woman_holding_hands_medium_dark_skin_tone_medium_skin_tone
	"👩🏾‍🤝‍👨🏽",	//woman_and_man_holding_hands_medium_dark_skin_tone_medium_skin_tone
	"👩🏾‍🤝‍👨🏽",	//couple_medium_dark_skin_tone_medium_skin_tone
	"👩🏾‍🤝‍👨🏿",	//man_and_woman_holding_hands_medium_dark_skin_tone_dark_skin_tone
	"👩🏾‍🤝‍👨🏿",	//woman_and_man_holding_hands_medium_dark_skin_tone_dark_skin_tone
	"👩🏾‍🤝‍👨🏿",	//couple_medium_dark_skin_tone_dark_skin_tone
	"👩🏿‍🤝‍👨🏻",	//man_and_woman_holding_hands_dark_skin_tone_light_skin_tone
	"👩🏿‍🤝‍👨🏻",	//woman_and_man_holding_hands_dark_skin_tone_light_skin_tone
	"👩🏿‍🤝‍👨🏻",	//couple_dark_skin_tone_light_skin_tone
	"👩🏿‍🤝‍👨🏼",	//man_and_woman_holding_hands_dark_skin_tone_medium_light_skin_tone
	"👩🏿‍🤝‍👨🏼",	//woman_and_man_holding_hands_dark_skin_tone_medium_light_skin_tone
	"👩🏿‍🤝‍👨🏼",	//couple_dark_skin_tone_medium_light_skin_tone
	"👩🏿‍🤝‍👨🏽",	//man_and_woman_holding_hands_dark_skin_tone_medium_skin_tone
	"👩🏿‍🤝‍👨🏽",	//woman_and_man_holding_hands_dark_skin_tone_medium_skin_tone
	"👩🏿‍🤝‍👨🏽",	//couple_dark_skin_tone_medium_skin_tone
	"👩🏿‍🤝‍👨🏾",	//man_and_woman_holding_hands_dark_skin_tone_medium_dark_skin_tone
	"👩🏿‍🤝‍👨🏾",	//woman_and_man_holding_hands_dark_skin_tone_medium_dark_skin_tone
	"👩🏿‍🤝‍👨🏾",	//couple_dark_skin_tone_medium_dark_skin_tone
	"👬🏻",	//two_men_holding_hands_light_skin_tone
	"👬🏻",	//men_holding_hands_light_skin_tone
	"👬🏼",	//two_men_holding_hands_medium_light_skin_tone
	"👬🏼",	//men_holding_hands_medium_light_skin_tone
	"👬🏽",	//two_men_holding_hands_medium_skin_tone
	"👬🏽",	//men_holding_hands_medium_skin_tone
	"👬🏾",	//two_men_holding_hands_medium_dark_skin_tone
	"👬🏾",	//men_holding_hands_medium_dark_skin_tone
	"👬🏿",	//two_men_holding_hands_dark_skin_tone
	"👬🏿",	//men_holding_hands_dark_skin_tone
	"👨🏻‍🤝‍👨🏼",	//two_men_holding_hands_light_skin_tone_medium_light_skin_tone
	"👨🏻‍🤝‍👨🏼",	//men_holding_hands_light_skin_tone_medium_light_skin_tone
	"👨🏻‍🤝‍👨🏽",	//two_men_holding_hands_light_skin_tone_medium_skin_tone
	"👨🏻‍🤝‍👨🏽",	//men_holding_hands_light_skin_tone_medium_skin_tone
	"👨🏻‍🤝‍👨🏾",	//two_men_holding_hands_light_skin_tone_medium_dark_skin_tone
	"👨🏻‍🤝‍👨🏾",	//men_holding_hands_light_skin_tone_medium_dark_skin_tone
	"👨🏻‍🤝‍👨🏿",	//two_men_holding_hands_light_skin_tone_dark_skin_tone
	"👨🏻‍🤝‍👨🏿",	//men_holding_hands_light_skin_tone_dark_skin_tone
	"👨🏼‍🤝‍👨🏻",	//two_men_holding_hands_medium_light_skin_tone_light_skin_tone
	"👨🏼‍🤝‍👨🏻",	//men_holding_hands_medium_light_skin_tone_light_skin_tone
	"👨🏼‍🤝‍👨🏽",	//two_men_holding_hands_medium_light_skin_tone_medium_skin_tone
	"👨🏼‍🤝‍👨🏽",	//men_holding_hands_medium_light_skin_tone_medium_skin_tone
	"👨🏼‍🤝‍👨🏾",	//two_men_holding_hands_medium_light_skin_tone_medium_dark_skin_tone
	"👨🏼‍🤝‍👨🏾",	//men_holding_hands_medium_light_skin_tone_medium_dark_skin_tone
	"👨🏼‍🤝‍👨🏿",	//two_men_holding_hands_medium_light_skin_tone_dark_skin_tone
	"👨🏼‍🤝‍👨🏿",	//men_holding_hands_medium_light_skin_tone_dark_skin_tone
	"👨🏽‍🤝‍👨🏻",	//two_men_holding_hands_medium_skin_tone_light_skin_tone
	"👨🏽‍🤝‍👨🏻",	//men_holding_hands_medium_skin_tone_light_skin_tone
	"👨🏽‍🤝‍👨🏼",	//two_men_holding_hands_medium_skin_tone_medium_light_skin_tone
	"👨🏽‍🤝‍👨🏼",	//men_holding_hands_medium_skin_tone_medium_light_skin_tone
	"👨🏽‍🤝‍👨🏾",	//two_men_holding_hands_medium_skin_tone_medium_dark_skin_tone
	"👨🏽‍🤝‍👨🏾",	//men_holding_hands_medium_skin_tone_medium_dark_skin_tone
	"👨🏽‍🤝‍👨🏿",	//two_men_holding_hands_medium_skin_tone_dark_skin_tone
	"👨🏽‍🤝‍👨🏿",	//men_holding_hands_medium_skin_tone_dark_skin_tone
	"👨🏾‍🤝‍👨🏻",	//two_men_holding_hands_medium_dark_skin_tone_light_skin_tone
	"👨🏾‍🤝‍👨🏻",	//men_holding_hands_medium_dark_skin_tone_light_skin_tone
	"👨🏾‍🤝‍👨🏼",	//two_men_holding_hands_medium_dark_skin_tone_medium_light_skin_tone
	"👨🏾‍🤝‍👨🏼",	//men_holding_hands_medium_dark_skin_tone_medium_light_skin_tone
	"👨🏾‍🤝‍👨🏽",	//two_men_holding_hands_medium_dark_skin_tone_medium_skin_tone
	"👨🏾‍🤝‍👨🏽",	//men_holding_hands_medium_dark_skin_tone_medium_skin_tone
	"👨🏾‍🤝‍👨🏿",	//two_men_holding_hands_medium_dark_skin_tone_dark_skin_tone
	"👨🏾‍🤝‍👨🏿",	//men_holding_hands_medium_dark_skin_tone_dark_skin_tone
	"👨🏿‍🤝‍👨🏻",	//two_men_holding_hands_dark_skin_tone_light_skin_tone
	"👨🏿‍🤝‍👨🏻",	//men_holding_hands_dark_skin_tone_light_skin_tone
	"👨🏿‍🤝‍👨🏼",	//two_men_holding_hands_dark_skin_tone_medium_light_skin_tone
	"👨🏿‍🤝‍👨🏼",	//men_holding_hands_dark_skin_tone_medium_light_skin_tone
	"👨🏿‍🤝‍👨🏽",	//two_men_holding_hands_dark_skin_tone_medium_skin_tone
	"👨🏿‍🤝‍👨🏽",	//men_holding_hands_dark_skin_tone_medium_skin_tone
	"👨🏿‍🤝‍👨🏾",	//two_men_holding_hands_dark_skin_tone_medium_dark_skin_tone
	"👨🏿‍🤝‍👨🏾",	//men_holding_hands_dark_skin_tone_medium_dark_skin_tone
	"👭🏻",	//two_women_holding_hands_light_skin_tone
	"👭🏻",	//women_holding_hands_light_skin_tone
	"👭🏼",	//two_women_holding_hands_medium_light_skin_tone
	"👭🏼",	//women_holding_hands_medium_light_skin_tone
	"👭🏽",	//two_women_holding_hands_medium_skin_tone
	"👭🏽",	//women_holding_hands_medium_skin_tone
	"👭🏾",	//two_women_holding_hands_medium_dark_skin_tone
	"👭🏾",	//women_holding_hands_medium_dark_skin_tone
	"👭🏿",	//two_women_holding_hands_dark_skin_tone
	"👭🏿",	//women_holding_hands_dark_skin_tone
	"👩🏻‍🤝‍👩🏼",	//two_women_holding_hands_light_skin_tone_medium_light_skin_tone
	"👩🏻‍🤝‍👩🏼",	//women_holding_hands_light_skin_tone_medium_light_skin_tone
	"👩🏻‍🤝‍👩🏽",	//two_women_holding_hands_light_skin_tone_medium_skin_tone
	"👩🏻‍🤝‍👩🏽",	//women_holding_hands_light_skin_tone_medium_skin_tone
	"👩🏻‍🤝‍👩🏾",	//two_women_holding_hands_light_skin_tone_medium_dark_skin_tone
	"👩🏻‍🤝‍👩🏾",	//women_holding_hands_light_skin_tone_medium_dark_skin_tone
	"👩🏻‍🤝‍👩🏿",	//two_women_holding_hands_light_skin_tone_dark_skin_tone
	"👩🏻‍🤝‍👩🏿",	//women_holding_hands_light_skin_tone_dark_skin_tone
	"👩🏼‍🤝‍👩🏻",	//two_women_holding_hands_medium_light_skin_tone_light_skin_tone
	"👩🏼‍🤝‍👩🏻",	//women_holding_hands_medium_light_skin_tone_light_skin_tone
	"👩🏼‍🤝‍👩🏽",	//two_women_holding_hands_medium_light_skin_tone_medium_skin_tone
	"👩🏼‍🤝‍👩🏽",	//women_holding_hands_medium_light_skin_tone_medium_skin_tone
	"👩🏼‍🤝‍👩🏾",	//two_women_holding_hands_medium_light_skin_tone_medium_dark_skin_tone
	"👩🏼‍🤝‍👩🏾",	//women_holding_hands_medium_light_skin_tone_medium_dark_skin_tone
	"👩🏼‍🤝‍👩🏿",	//two_women_holding_hands_medium_light_skin_tone_dark_skin_tone
	"👩🏼‍🤝‍👩🏿",	//women_holding_hands_medium_light_skin_tone_dark_skin_tone
	"👩🏽‍🤝‍👩🏻",	//two_women_holding_hands_medium_skin_tone_light_skin_tone
	"👩🏽‍🤝‍👩🏻",	//women_holding_hands_medium_skin_tone_light_skin_tone
	"👩🏽‍🤝‍👩🏼",	//two_women_holding_hands_medium_skin_tone_medium_light_skin_tone
	"👩🏽‍🤝‍👩🏼",	//women_holding_hands_medium_skin_tone_medium_light_skin_tone
	"👩🏽‍🤝‍👩🏾",	//two_women_holding_hands_medium_skin_tone_medium_dark_skin_tone
	"👩🏽‍🤝‍👩🏾",	//women_holding_hands_medium_skin_tone_medium_dark_skin_tone
	"👩🏽‍🤝‍👩🏿",	//two_women_holding_hands_medium_skin_tone_dark_skin_tone
	"👩🏽‍🤝‍👩🏿",	//women_holding_hands_medium_skin_tone_dark_skin_tone
	"👩🏾‍🤝‍👩🏻",	//two_women_holding_hands_medium_dark_skin_tone_light_skin_tone
	"👩🏾‍🤝‍👩🏻",	//women_holding_hands_medium_dark_skin_tone_light_skin_tone
	"👩🏾‍🤝‍👩🏼",	//two_women_holding_hands_medium_dark_skin_tone_medium_light_skin_tone
	"👩🏾‍🤝‍👩🏼",	//women_holding_hands_medium_dark_skin_tone_medium_light_skin_tone
	"👩🏾‍🤝‍👩🏽",	//two_women_holding_hands_medium_dark_skin_tone_medium_skin_tone
	"👩🏾‍🤝‍👩🏽",	//women_holding_hands_medium_dark_skin_tone_medium_skin_tone
	"👩🏾‍🤝‍👩🏿",	//two_women_holding_hands_medium_dark_skin_tone_dark_skin_tone
	"👩🏾‍🤝‍👩🏿",	//women_holding_hands_medium_dark_skin_tone_dark_skin_tone
	"👩🏿‍🤝‍👩🏻",	//two_women_holding_hands_dark_skin_tone_light_skin_tone
	"👩🏿‍🤝‍👩🏻",	//women_holding_hands_dark_skin_tone_light_skin_tone
	"👩🏿‍🤝‍👩🏼",	//two_women_holding_hands_dark_skin_tone_medium_light_skin_tone
	"👩🏿‍🤝‍👩🏼",	//women_holding_hands_dark_skin_tone_medium_light_skin_tone
	"👩🏿‍🤝‍👩🏽",	//two_women_holding_hands_dark_skin_tone_medium_skin_tone
	"👩🏿‍🤝‍👩🏽",	//women_holding_hands_dark_skin_tone_medium_skin_tone
	"👩🏿‍🤝‍👩🏾",	//two_women_holding_hands_dark_skin_tone_medium_dark_skin_tone
	"👩🏿‍🤝‍👩🏾",	//women_holding_hands_dark_skin_tone_medium_dark_skin_tone
	"👮🏻‍♀️",	//female-police-officer_light_skin_tone
	"👮🏻‍♀️",	//policewoman_light_skin_tone
	"👮🏼‍♀️",	//female-police-officer_medium_light_skin_tone
	"👮🏼‍♀️",	//policewoman_medium_light_skin_tone
	"👮🏽‍♀️",	//female-police-officer_medium_skin_tone
	"👮🏽‍♀️",	//policewoman_medium_skin_tone
	"👮🏾‍♀️",	//female-police-officer_medium_dark_skin_tone
	"👮🏾‍♀️",	//policewoman_medium_dark_skin_tone
	"👮🏿‍♀️",	//female-police-officer_dark_skin_tone
	"👮🏿‍♀️",	//policewoman_dark_skin_tone
	"👮🏻‍♂️",	//male-police-officer_light_skin_tone
	"👮🏻‍♂️",	//policeman_light_skin_tone
	"👮🏼‍♂️",	//male-police-officer_medium_light_skin_tone
	"👮🏼‍♂️",	//policeman_medium_light_skin_tone
	"👮🏽‍♂️",	//male-police-officer_medium_skin_tone
	"👮🏽‍♂️",	//policeman_medium_skin_tone
	"👮🏾‍♂️",	//male-police-officer_medium_dark_skin_tone
	"👮🏾‍♂️",	//policeman_medium_dark_skin_tone
	"👮🏿‍♂️",	//male-police-officer_dark_skin_tone
	"👮🏿‍♂️",	//policeman_dark_skin_tone
	"👮🏻",	//cop_light_skin_tone
	"👮🏼",	//cop_medium_light_skin_tone
	"👮🏽",	//cop_medium_skin_tone
	"👮🏾",	//cop_medium_dark_skin_tone
	"👮🏿",	//cop_dark_skin_tone
	"👰🏻‍♀️",	//woman_with_veil_light_skin_tone
	"👰🏼‍♀️",	//woman_with_veil_medium_light_skin_tone
	"👰🏽‍♀️",	//woman_with_veil_medium_skin_tone
	"👰🏾‍♀️",	//woman_with_veil_medium_dark_skin_tone
	"👰🏿‍♀️",	//woman_with_veil_dark_skin_tone
	"👰🏻‍♂️",	//man_with_veil_light_skin_tone
	"👰🏼‍♂️",	//man_with_veil_medium_light_skin_tone
	"👰🏽‍♂️",	//man_with_veil_medium_skin_tone
	"👰🏾‍♂️",	//man_with_veil_medium_dark_skin_tone
	"👰🏿‍♂️",	//man_with_veil_dark_skin_tone
	"👰🏻",	//bride_with_veil_light_skin_tone
	"👰🏼",	//bride_with_veil_medium_light_skin_tone
	"👰🏽",	//bride_with_veil_medium_skin_tone
	"👰🏾",	//bride_with_veil_medium_dark_skin_tone
	"👰🏿",	//bride_with_veil_dark_skin_tone
	"👱🏻‍♀️",	//blond-haired-woman_light_skin_tone
	"👱🏻‍♀️",	//blonde_woman_light_skin_tone
	"👱🏼‍♀️",	//blond-haired-woman_medium_light_skin_tone
	"👱🏼‍♀️",	//blonde_woman_medium_light_skin_tone
	"👱🏽‍♀️",	//blond-haired-woman_medium_skin_tone
	"👱🏽‍♀️",	//blonde_woman_medium_skin_tone
	"👱🏾‍♀️",	//blond-haired-woman_medium_dark_skin_tone
	"👱🏾‍♀️",	//blonde_woman_medium_dark_skin_tone
	"👱🏿‍♀️",	//blond-haired-woman_dark_skin_tone
	"👱🏿‍♀️",	//blonde_woman_dark_skin_tone
	"👱🏻‍♂️",	//blond-haired-man_light_skin_tone
	"👱🏻‍♂️",	//blonde_man_light_skin_tone
	"👱🏼‍♂️",	//blond-haired-man_medium_light_skin_tone
	"👱🏼‍♂️",	//blonde_man_medium_light_skin_tone
	"👱🏽‍♂️",	//blond-haired-man_medium_skin_tone
	"👱🏽‍♂️",	//blonde_man_medium_skin_tone
	"👱🏾‍♂️",	//blond-haired-man_medium_dark_skin_tone
	"👱🏾‍♂️",	//blonde_man_medium_dark_skin_tone
	"👱🏿‍♂️",	//blond-haired-man_dark_skin_tone
	"👱🏿‍♂️",	//blonde_man_dark_skin_tone
	"👱🏻",	//person_with_blond_hair_light_skin_tone
	"👱🏼",	//person_with_blond_hair_medium_light_skin_tone
	"👱🏽",	//person_with_blond_hair_medium_skin_tone
	"👱🏾",	//person_with_blond_hair_medium_dark_skin_tone
	"👱🏿",	//person_with_blond_hair_dark_skin_tone
	"👲🏻",	//man_with_gua_pi_mao_light_skin_tone
	"👲🏼",	//man_with_gua_pi_mao_medium_light_skin_tone
	"👲🏽",	//man_with_gua_pi_mao_medium_skin_tone
	"👲🏾",	//man_with_gua_pi_mao_medium_dark_skin_tone
	"👲🏿",	//man_with_gua_pi_mao_dark_skin_tone
	"👳🏻‍♀️",	//woman-wearing-turban_light_skin_tone
	"👳🏻‍♀️",	//woman_with_turban_light_skin_tone
	"👳🏼‍♀️",	//woman-wearing-turban_medium_light_skin_tone
	"👳🏼‍♀️",	//woman_with_turban_medium_light_skin_tone
	"👳🏽‍♀️",	//woman-wearing-turban_medium_skin_tone
	"👳🏽‍♀️",	//woman_with_turban_medium_skin_tone
	"👳🏾‍♀️",	//woman-wearing-turban_medium_dark_skin_tone
	"👳🏾‍♀️",	//woman_with_turban_medium_dark_skin_tone
	"👳🏿‍♀️",	//woman-wearing-turban_dark_skin_tone
	"👳🏿‍♀️",	//woman_with_turban_dark_skin_tone
	"👳🏻‍♂️",	//man-wearing-turban_light_skin_tone
	"👳🏼‍♂️",	//man-wearing-turban_medium_light_skin_tone
	"👳🏽‍♂️",	//man-wearing-turban_medium_skin_tone
	"👳🏾‍♂️",	//man-wearing-turban_medium_dark_skin_tone
	"👳🏿‍♂️",	//man-wearing-turban_dark_skin_tone
	"👳🏻",	//man_with_turban_light_skin_tone
	"👳🏼",	//man_with_turban_medium_light_skin_tone
	"👳🏽",	//man_with_turban_medium_skin_tone
	"👳🏾",	//man_with_turban_medium_dark_skin_tone
	"👳🏿",	//man_with_turban_dark_skin_tone
	"👴🏻",	//older_man_light_skin_tone
	"👴🏼",	//older_man_medium_light_skin_tone
	"👴🏽",	//older_man_medium_skin_tone
	"👴🏾",	//older_man_medium_dark_skin_tone
	"👴🏿",	//older_man_dark_skin_tone
	"👵🏻",	//older_woman_light_skin_tone
	"👵🏼",	//older_woman_medium_light_skin_tone
	"👵🏽",	//older_woman_medium_skin_tone
	"👵🏾",	//older_woman_medium_dark_skin_tone
	"👵🏿",	//older_woman_dark_skin_tone
	"👶🏻",	//baby_light_skin_tone
	"👶🏼",	//baby_medium_light_skin_tone
	"👶🏽",	//baby_medium_skin_tone
	"👶🏾",	//baby_medium_dark_skin_tone
	"👶🏿",	//baby_dark_skin_tone
	"👷🏻‍♀️",	//female-construction-worker_light_skin_tone
	"👷🏻‍♀️",	//construction_worker_woman_light_skin_tone
	"👷🏼‍♀️",	//female-construction-worker_medium_light_skin_tone
	"👷🏼‍♀️",	//construction_worker_woman_medium_light_skin_tone
	"👷🏽‍♀️",	//female-construction-worker_medium_skin_tone
	"👷🏽‍♀️",	//construction_worker_woman_medium_skin_tone
	"👷🏾‍♀️",	//female-construction-worker_medium_dark_skin_tone
	"👷🏾‍♀️",	//construction_worker_woman_medium_dark_skin_tone
	"👷🏿‍♀️",	//female-construction-worker_dark_skin_tone
	"👷🏿‍♀️",	//construction_worker_woman_dark_skin_tone
	"👷🏻‍♂️",	//male-construction-worker_light_skin_tone
	"👷🏻‍♂️",	//construction_worker_man_light_skin_tone
	"👷🏼‍♂️",	//male-construction-worker_medium_light_skin_tone
	"👷🏼‍♂️",	//construction_worker_man_medium_light_skin_tone
	"👷🏽‍♂️",	//male-construction-worker_medium_skin_tone
	"👷🏽‍♂️",	//construction_worker_man_medium_skin_tone
	"👷🏾‍♂️",	//male-construction-worker_medium_dark_skin_tone
	"👷🏾‍♂️",	//construction_worker_man_medium_dark_skin_tone
	"👷🏿‍♂️",	//male-construction-worker_dark_skin_tone
	"👷🏿‍♂️",	//construction_worker_man_dark_skin_tone
	"👷🏻",	//construction_worker_light_skin_tone
	"👷🏼",	//construction_worker_medium_light_skin_tone
	"👷🏽",	//construction_worker_medium_skin_tone
	"👷🏾",	//construction_worker_medium_dark_skin_tone
	"👷🏿",	//construction_worker_dark_skin_tone
	"👸🏻",	//princess_light_skin_tone
	"👸🏼",	//princess_medium_light_skin_tone
	"👸🏽",	//princess_medium_skin_tone
	"👸🏾",	//princess_medium_dark_skin_tone
	"👸🏿",	//princess_dark_skin_tone
	"👼🏻",	//angel_light_skin_tone
	"👼🏼",	//angel_medium_light_skin_tone
	"👼🏽",	//angel_medium_skin_tone
	"👼🏾",	//angel_medium_dark_skin_tone
	"👼🏿",	//angel_dark_skin_tone
	"💁🏻‍♀️",	//woman-tipping-hand_light_skin_tone
	"💁🏻‍♀️",	//tipping_hand_woman_light_skin_tone
	"💁🏼‍♀️",	//woman-tipping-hand_medium_light_skin_tone
	"💁🏼‍♀️",	//tipping_hand_woman_medium_light_skin_tone
	"💁🏽‍♀️",	//woman-tipping-hand_medium_skin_tone
	"💁🏽‍♀️",	//tipping_hand_woman_medium_skin_tone
	"💁🏾‍♀️",	//woman-tipping-hand_medium_dark_skin_tone
	"💁🏾‍♀️",	//tipping_hand_woman_medium_dark_skin_tone
	"💁🏿‍♀️",	//woman-tipping-hand_dark_skin_tone
	"💁🏿‍♀️",	//tipping_hand_woman_dark_skin_tone
	"💁🏻‍♂️",	//man-tipping-hand_light_skin_tone
	"💁🏻‍♂️",	//tipping_hand_man_light_skin_tone
	"💁🏼‍♂️",	//man-tipping-hand_medium_light_skin_tone
	"💁🏼‍♂️",	//tipping_hand_man_medium_light_skin_tone
	"💁🏽‍♂️",	//man-tipping-hand_medium_skin_tone
	"💁🏽‍♂️",	//tipping_hand_man_medium_skin_tone
	"💁🏾‍♂️",	//man-tipping-hand_medium_dark_skin_tone
	"💁🏾‍♂️",	//tipping_hand_man_medium_dark_skin_tone
	"💁🏿‍♂️",	//man-tipping-hand_dark_skin_tone
	"💁🏿‍♂️",	//tipping_hand_man_dark_skin_tone
	"💁🏻",	//information_desk_person_light_skin_tone
	"💁🏼",	//information_desk_person_medium_light_skin_tone
	"💁🏽",	//information_desk_person_medium_skin_tone
	"💁🏾",	//information_desk_person_medium_dark_skin_tone
	"💁🏿",	//information_desk_person_dark_skin_tone
	"💂🏻‍♀️",	//female-guard_light_skin_tone
	"💂🏻‍♀️",	//guardswoman_light_skin_tone
	"💂🏼‍♀️",	//female-guard_medium_light_skin_tone
	"💂🏼‍♀️",	//guardswoman_medium_light_skin_tone
	"💂🏽‍♀️",	//female-guard_medium_skin_tone
	"💂🏽‍♀️",	//guardswoman_medium_skin_tone
	"💂🏾‍♀️",	//female-guard_medium_dark_skin_tone
	"💂🏾‍♀️",	//guardswoman_medium_dark_skin_tone
	"💂🏿‍♀️",	//female-guard_dark_skin_tone
	"💂🏿‍♀️",	//guardswoman_dark_skin_tone
	"💂🏻‍♂️",	//male-guard_light_skin_tone
	"💂🏼‍♂️",	//male-guard_medium_light_skin_tone
	"💂🏽‍♂️",	//male-guard_medium_skin_tone
	"💂🏾‍♂️",	//male-guard_medium_dark_skin_tone
	"💂🏿‍♂️",	//male-guard_dark_skin_tone
	"💂🏻",	//guardsman_light_skin_tone
	"💂🏼",	//guardsman_medium_light_skin_tone
	"💂🏽",	//guardsman_medium_skin_tone
	"💂🏾",	//guardsman_medium_dark_skin_tone
	"💂🏿",	//guardsman_dark_skin_tone
	"💃🏻",	//dancer_light_skin_tone
	"💃🏼",	//dancer_medium_light_skin_tone
	"💃🏽",	//dancer_medium_skin_tone
	"💃🏾",	//dancer_medium_dark_skin_tone
	"💃🏿",	//dancer_dark_skin_tone
	"💅🏻",	//nail_care_light_skin_tone
	"💅🏼",	//nail_care_medium_light_skin_tone
	"💅🏽",	//nail_care_medium_skin_tone
	"💅🏾",	//nail_care_medium_dark_skin_tone
	"💅🏿",	//nail_care_dark_skin_tone
	"💆🏻‍♀️",	//woman-getting-massage_light_skin_tone
	"💆🏻‍♀️",	//massage_woman_light_skin_tone
	"💆🏼‍♀️",	//woman-getting-massage_medium_light_skin_tone
	"💆🏼‍♀️",	//massage_woman_medium_light_skin_tone
	"💆🏽‍♀️",	//woman-getting-massage_medium_skin_tone
	"💆🏽‍♀️",	//massage_woman_medium_skin_tone
	"💆🏾‍♀️",	//woman-getting-massage_medium_dark_skin_tone
	"💆🏾‍♀️",	//massage_woman_medium_dark_skin_tone
	"💆🏿‍♀️",	//woman-getting-massage_dark_skin_tone
	"💆🏿‍♀️",	//massage_woman_dark_skin_tone
	"💆🏻‍♂️",	//man-getting-massage_light_skin_tone
	"💆🏻‍♂️",	//massage_man_light_skin_tone
	"💆🏼‍♂️",	//man-getting-massage_medium_light_skin_tone
	"💆🏼‍♂️",	//massage_man_medium_light_skin_tone
	"💆🏽‍♂️",	//man-getting-massage_medium_skin_tone
	"💆🏽‍♂️",	//massage_man_medium_skin_tone
	"💆🏾‍♂️",	//man-getting-massage_medium_dark_skin_tone
	"💆🏾‍♂️",	//massage_man_medium_dark_skin_tone
	"💆🏿‍♂️",	//man-getting-massage_dark_skin_tone
	"💆🏿‍♂️",	//massage_man_dark_skin_tone
	"💆🏻",	//massage_light_skin_tone
	"💆🏼",	//massage_medium_light_skin_tone
	"💆🏽",	//massage_medium_skin_tone
	"💆🏾",	//massage_medium_dark_skin_tone
	"💆🏿",	//massage_dark_skin_tone
	"💇🏻‍♀️",	//woman-getting-haircut_light_skin_tone
	"💇🏻‍♀️",	//haircut_woman_light_skin_tone
	"💇🏼‍♀️",	//woman-getting-haircut_medium_light_skin_tone
	"💇🏼‍♀️",	//haircut_woman_medium_light_skin_tone
	"💇🏽‍♀️",	//woman-getting-haircut_medium_skin_tone
	"💇🏽‍♀️",	//haircut_woman_medium_skin_tone
	"💇🏾‍♀️",	//woman-getting-haircut_medium_dark_skin_tone
	"💇🏾‍♀️",	//haircut_woman_medium_dark_skin_tone
	"💇🏿‍♀️",	//woman-getting-haircut_dark_skin_tone
	"💇🏿‍♀️",	//haircut_woman_dark_skin_tone
	"💇🏻‍♂️",	//man-getting-haircut_light_skin_tone
	"💇🏻‍♂️",	//haircut_man_light_skin_tone
	"💇🏼‍♂️",	//man-getting-haircut_medium_light_skin_tone
	"💇🏼‍♂️",	//haircut_man_medium_light_skin_tone
	"💇🏽‍♂️",	//man-getting-haircut_medium_skin_tone
	"💇🏽‍♂️",	//haircut_man_medium_skin_tone
	"💇🏾‍♂️",	//man-getting-haircut_medium_dark_skin_tone
	"💇🏾‍♂️",	//haircut_man_medium_dark_skin_tone
	"💇🏿‍♂️",	//man-getting-haircut_dark_skin_tone
	"💇🏿‍♂️",	//haircut_man_dark_skin_tone
	"💇🏻",	//haircut_light_skin_tone
	"💇🏼",	//haircut_medium_light_skin_tone
	"💇🏽",	//haircut_medium_skin_tone
	"💇🏾",	//haircut_medium_dark_skin_tone
	"💇🏿",	//haircut_dark_skin_tone
	"💪🏻",	//muscle_light_skin_tone
	"💪🏼",	//muscle_medium_light_skin_tone
	"💪🏽",	//muscle_medium_skin_tone
	"💪🏾",	//muscle_medium_dark_skin_tone
	"💪🏿",	//muscle_dark_skin_tone
	"🕴🏻",	//man_in_business_suit_levitating_light_skin_tone
	"🕴🏻",	//business_suit_levitating_light_skin_tone
	"🕴🏼",	//man_in_business_suit_levitating_medium_light_skin_tone
	"🕴🏼",	//business_suit_levitating_medium_light_skin_tone
	"🕴🏽",	//man_in_business_suit_levitating_medium_skin_tone
	"🕴🏽",	//business_suit_levitating_medium_skin_tone
	"🕴🏾",	//man_in_business_suit_levitating_medium_dark_skin_tone
	"🕴🏾",	//business_suit_levitating_medium_dark_skin_tone
	"🕴🏿",	//man_in_business_suit_levitating_dark_skin_tone
	"🕴🏿",	//business_suit_levitating_dark_skin_tone
	"🕵🏻‍♀️",	//female-detective_light_skin_tone
	"🕵🏻‍♀️",	//female_detective_light_skin_tone
	"🕵🏼‍♀️",	//female-detective_medium_light_skin_tone
	"🕵🏼‍♀️",	//female_detective_medium_light_skin_tone
	"🕵🏽‍♀️",	//female-detective_medium_skin_tone
	"🕵🏽‍♀️",	//female_detective_medium_skin_tone
	"🕵🏾‍♀️",	//female-detective_medium_dark_skin_tone
	"🕵🏾‍♀️",	//female_detective_medium_dark_skin_tone
	"🕵🏿‍♀️",	//female-detective_dark_skin_tone
	"🕵🏿‍♀️",	//female_detective_dark_skin_tone
	"🕵🏻‍♂️",	//male-detective_light_skin_tone
	"🕵🏻‍♂️",	//male_detective_light_skin_tone
	"🕵🏼‍♂️",	//male-detective_medium_light_skin_tone
	"🕵🏼‍♂️",	//male_detective_medium_light_skin_tone
	"🕵🏽‍♂️",	//male-detective_medium_skin_tone
	"🕵🏽‍♂️",	//male_detective_medium_skin_tone
	"🕵🏾‍♂️",	//male-detective_medium_dark_skin_tone
	"🕵🏾‍♂️",	//male_detective_medium_dark_skin_tone
	"🕵🏿‍♂️",	//male-detective_dark_skin_tone
	"🕵🏿‍♂️",	//male_detective_dark_skin_tone
	"🕵🏻",	//sleuth_or_spy_light_skin_tone
	"🕵🏼",	//sleuth_or_spy_medium_light_skin_tone
	"🕵🏽",	//sleuth_or_spy_medium_skin_tone
	"🕵🏾",	//sleuth_or_spy_medium_dark_skin_tone
	"🕵🏿",	//sleuth_or_spy_dark_skin_tone
	"🕺🏻",	//man_dancing_light_skin_tone
	"🕺🏼",	//man_dancing_medium_light_skin_tone
	"🕺🏽",	//man_dancing_medium_skin_tone
	"🕺🏾",	//man_dancing_medium_dark_skin_tone
	"🕺🏿",	//man_dancing_dark_skin_tone
	"🖐🏻",	//raised_hand_with_fingers_splayed_light_skin_tone
	"🖐🏼",	//raised_hand_with_fingers_splayed_medium_light_skin_tone
	"🖐🏽",	//raised_hand_with_fingers_splayed_medium_skin_tone
	"🖐🏾",	//raised_hand_with_fingers_splayed_medium_dark_skin_tone
	"🖐🏿",	//raised_hand_with_fingers_splayed_dark_skin_tone
	"🖕🏻",	//middle_finger_light_skin_tone
	"🖕🏻",	//reversed_hand_with_middle_finger_extended_light_skin_tone
	"🖕🏼",	//middle_finger_medium_light_skin_tone
	"🖕🏼",	//reversed_hand_with_middle_finger_extended_medium_light_skin_tone
	"🖕🏽",	//middle_finger_medium_skin_tone
	"🖕🏽",	//reversed_hand_with_middle_finger_extended_medium_skin_tone
	"🖕🏾",	//middle_finger_medium_dark_skin_tone
	"🖕🏾",	//reversed_hand_with_middle_finger_extended_medium_dark_skin_tone
	"🖕🏿",	//middle_finger_dark_skin_tone
	"🖕🏿",	//reversed_hand_with_middle_finger_extended_dark_skin_tone
	"🖖🏻",	//spock-hand_light_skin_tone
	"🖖🏻",	//vulcan_salute_light_skin_tone
	"🖖🏼",	//spock-hand_medium_light_skin_tone
	"🖖🏼",	//vulcan_salute_medium_light_skin_tone
	"🖖🏽",	//spock-hand_medium_skin_tone
	"🖖🏽",	//vulcan_salute_medium_skin_tone
	"🖖🏾",	//spock-hand_medium_dark_skin_tone
	"🖖🏾",	//vulcan_salute_medium_dark_skin_tone
	"🖖🏿",	//spock-hand_dark_skin_tone
	"🖖🏿",	//vulcan_salute_dark_skin_tone
	"🙅🏻‍♀️",	//woman-gesturing-no_light_skin_tone
	"🙅🏻‍♀️",	//no_good_woman_light_skin_tone
	"🙅🏼‍♀️",	//woman-gesturing-no_medium_light_skin_tone
	"🙅🏼‍♀️",	//no_good_woman_medium_light_skin_tone
	"🙅🏽‍♀️",	//woman-gesturing-no_medium_skin_tone
	"🙅🏽‍♀️",	//no_good_woman_medium_skin_tone
	"🙅🏾‍♀️",	//woman-gesturing-no_medium_dark_skin_tone
	"🙅🏾‍♀️",	//no_good_woman_medium_dark_skin_tone
	"🙅🏿‍♀️",	//woman-gesturing-no_dark_skin_tone
	"🙅🏿‍♀️",	//no_good_woman_dark_skin_tone
	"🙅🏻‍♂️",	//man-gesturing-no_light_skin_tone
	"🙅🏻‍♂️",	//no_good_man_light_skin_tone
	"🙅🏼‍♂️",	//man-gesturing-no_medium_light_skin_tone
	"🙅🏼‍♂️",	//no_good_man_medium_light_skin_tone
	"🙅🏽‍♂️",	//man-gesturing-no_medium_skin_tone
	"🙅🏽‍♂️",	//no_good_man_medium_skin_tone
	"🙅🏾‍♂️",	//man-gesturing-no_medium_dark_skin_tone
	"🙅🏾‍♂️",	//no_good_man_medium_dark_skin_tone
	"🙅🏿‍♂️",	//man-gesturing-no_dark_skin_tone
	"🙅🏿‍♂️",	//no_good_man_dark_skin_tone
	"🙅🏻",	//no_good_light_skin_tone
	"🙅🏼",	//no_good_medium_light_skin_tone
	"🙅🏽",	//no_good_medium_skin_tone
	"🙅🏾",	//no_good_medium_dark_skin_tone
	"🙅🏿",	//no_good_dark_skin_tone
	"🙆🏻‍♀️",	//woman-gesturing-ok_light_skin_tone
	"🙆🏼‍♀️",	//woman-gesturing-ok_medium_light_skin_tone
	"🙆🏽‍♀️",	//woman-gesturing-ok_medium_skin_tone
	"🙆🏾‍♀️",	//woman-gesturing-ok_medium_dark_skin_tone
	"🙆🏿‍♀️",	//woman-gesturing-ok_dark_skin_tone
	"🙆🏻‍♂️",	//man-gesturing-ok_light_skin_tone
	"🙆🏻‍♂️",	//ok_man_light_skin_tone
	"🙆🏼‍♂️",	//man-gesturing-ok_medium_light_skin_tone
	"🙆🏼‍♂️",	//ok_man_medium_light_skin_tone
	"🙆🏽‍♂️",	//man-gesturing-ok_medium_skin_tone
	"🙆🏽‍♂️",	//ok_man_medium_skin_tone
	"🙆🏾‍♂️",	//man-gesturing-ok_medium_dark_skin_tone
	"🙆🏾‍♂️",	//ok_man_medium_dark_skin_tone
	"🙆🏿‍♂️",	//man-gesturing-ok_dark_skin_tone
	"🙆🏿‍♂️",	//ok_man_dark_skin_tone
	"🙆🏻",	//ok_woman_light_skin_tone
	"🙆🏼",	//ok_woman_medium_light_skin_tone
	"🙆🏽",	//ok_woman_medium_skin_tone
	"🙆🏾",	//ok_woman_medium_dark_skin_tone
	"🙆🏿",	//ok_woman_dark_skin_tone
	"🙇🏻‍♀️",	//woman-bowing_light_skin_tone
	"🙇🏻‍♀️",	//bowing_woman_light_skin_tone
	"🙇🏼‍♀️",	//woman-bowing_medium_light_skin_tone
	"🙇🏼‍♀️",	//bowing_woman_medium_light_skin_tone
	"🙇🏽‍♀️",	//woman-bowing_medium_skin_tone
	"🙇🏽‍♀️",	//bowing_woman_medium_skin_tone
	"🙇🏾‍♀️",	//woman-bowing_medium_dark_skin_tone
	"🙇🏾‍♀️",	//bowing_woman_medium_dark_skin_tone
	"🙇🏿‍♀️",	//woman-bowing_dark_skin_tone
	"🙇🏿‍♀️",	//bowing_woman_dark_skin_tone
	"🙇🏻‍♂️",	//man-bowing_light_skin_tone
	"🙇🏻‍♂️",	//bowing_man_light_skin_tone
	"🙇🏼‍♂️",	//man-bowing_medium_light_skin_tone
	"🙇🏼‍♂️",	//bowing_man_medium_light_skin_tone
	"🙇🏽‍♂️",	//man-bowing_medium_skin_tone
	"🙇🏽‍♂️",	//bowing_man_medium_skin_tone
	"🙇🏾‍♂️",	//man-bowing_medium_dark_skin_tone
	"🙇🏾‍♂️",	//bowing_man_medium_dark_skin_tone
	"🙇🏿‍♂️",	//man-bowing_dark_skin_tone
	"🙇🏿‍♂️",	//bowing_man_dark_skin_tone
	"🙇🏻",	//bow_light_skin_tone
	"🙇🏼",	//bow_medium_light_skin_tone
	"🙇🏽",	//bow_medium_skin_tone
	"🙇🏾",	//bow_medium_dark_skin_tone
	"🙇🏿",	//bow_dark_skin_tone
	"🙋🏻‍♀️",	//woman-raising-hand_light_skin_tone
	"🙋🏻‍♀️",	//raising_hand_woman_light_skin_tone
	"🙋🏼‍♀️",	//woman-raising-hand_medium_light_skin_tone
	"🙋🏼‍♀️",	//raising_hand_woman_medium_light_skin_tone
	"🙋🏽‍♀️",	//woman-raising-hand_medium_skin_tone
	"🙋🏽‍♀️",	//raising_hand_woman_medium_skin_tone
	"🙋🏾‍♀️",	//woman-raising-hand_medium_dark_skin_tone
	"🙋🏾‍♀️",	//raising_hand_woman_medium_dark_skin_tone
	"🙋🏿‍♀️",	//woman-raising-hand_dark_skin_tone
	"🙋🏿‍♀️",	//raising_hand_woman_dark_skin_tone
	"🙋🏻‍♂️",	//man-raising-hand_light_skin_tone
	"🙋🏻‍♂️",	//raising_hand_man_light_skin_tone
	"🙋🏼‍♂️",	//man-raising-hand_medium_light_skin_tone
	"🙋🏼‍♂️",	//raising_hand_man_medium_light_skin_tone
	"🙋🏽‍♂️",	//man-raising-hand_medium_skin_tone
	"🙋🏽‍♂️",	//raising_hand_man_medium_skin_tone
	"🙋🏾‍♂️",	//man-raising-hand_medium_dark_skin_tone
	"🙋🏾‍♂️",	//raising_hand_man_medium_dark_skin_tone
	"🙋🏿‍♂️",	//man-raising-hand_dark_skin_tone
	"🙋🏿‍♂️",	//raising_hand_man_dark_skin_tone
	"🙋🏻",	//raising_hand_light_skin_tone
	"🙋🏼",	//raising_hand_medium_light_skin_tone
	"🙋🏽",	//raising_hand_medium_skin_tone
	"🙋🏾",	//raising_hand_medium_dark_skin_tone
	"🙋🏿",	//raising_hand_dark_skin_tone
	"🙌🏻",	//raised_hands_light_skin_tone
	"🙌🏼",	//raised_hands_medium_light_skin_tone
	"🙌🏽",	//raised_hands_medium_skin_tone
	"🙌🏾",	//raised_hands_medium_dark_skin_tone
	"🙌🏿",	//raised_hands_dark_skin_tone
	"🙍🏻‍♀️",	//woman-frowning_light_skin_tone
	"🙍🏻‍♀️",	//frowning_woman_light_skin_tone
	"🙍🏼‍♀️",	//woman-frowning_medium_light_skin_tone
	"🙍🏼‍♀️",	//frowning_woman_medium_light_skin_tone
	"🙍🏽‍♀️",	//woman-frowning_medium_skin_tone
	"🙍🏽‍♀️",	//frowning_woman_medium_skin_tone
	"🙍🏾‍♀️",	//woman-frowning_medium_dark_skin_tone
	"🙍🏾‍♀️",	//frowning_woman_medium_dark_skin_tone
	"🙍🏿‍♀️",	//woman-frowning_dark_skin_tone
	"🙍🏿‍♀️",	//frowning_woman_dark_skin_tone
	"🙍🏻‍♂️",	//man-frowning_light_skin_tone
	"🙍🏻‍♂️",	//frowning_man_light_skin_tone
	"🙍🏼‍♂️",	//man-frowning_medium_light_skin_tone
	"🙍🏼‍♂️",	//frowning_man_medium_light_skin_tone
	"🙍🏽‍♂️",	//man-frowning_medium_skin_tone
	"🙍🏽‍♂️",	//frowning_man_medium_skin_tone
	"🙍🏾‍♂️",	//man-frowning_medium_dark_skin_tone
	"🙍🏾‍♂️",	//frowning_man_medium_dark_skin_tone
	"🙍🏿‍♂️",	//man-frowning_dark_skin_tone
	"🙍🏿‍♂️",	//frowning_man_dark_skin_tone
	"🙍🏻",	//person_frowning_light_skin_tone
	"🙍🏼",	//person_frowning_medium_light_skin_tone
	"🙍🏽",	//person_frowning_medium_skin_tone
	"🙍🏾",	//person_frowning_medium_dark_skin_tone
	"🙍🏿",	//person_frowning_dark_skin_tone
	"🙎🏻‍♀️",	//woman-pouting_light_skin_tone
	"🙎🏻‍♀️",	//pouting_woman_light_skin_tone
	"🙎🏼‍♀️",	//woman-pouting_medium_light_skin_tone
	"🙎🏼‍♀️",	//pouting_woman_medium_light_skin_tone
	"🙎🏽‍♀️",	//woman-pouting_medium_skin_tone
	"🙎🏽‍♀️",	//pouting_woman_medium_skin_tone
	"🙎🏾‍♀️",	//woman-pouting_medium_dark_skin_tone
	"🙎🏾‍♀️",	//pouting_woman_medium_dark_skin_tone
	"🙎🏿‍♀️",	//woman-pouting_dark_skin_tone
	"🙎🏿‍♀️",	//pouting_woman_dark_skin_tone
	"🙎🏻‍♂️",	//man-pouting_light_skin_tone
	"🙎🏻‍♂️",	//pouting_man_light_skin_tone
	"🙎🏼‍♂️",	//man-pouting_medium_light_skin_tone
	"🙎🏼‍♂️",	//pouting_man_medium_light_skin_tone
	"🙎🏽‍♂️",	//man-pouting_medium_skin_tone
	"🙎🏽‍♂️",	//pouting_man_medium_skin_tone
	"🙎🏾‍♂️",	//man-pouting_medium_dark_skin_tone
	"🙎🏾‍♂️",	//pouting_man_medium_dark_skin_tone
	"🙎🏿‍♂️",	//man-pouting_dark_skin_tone
	"🙎🏿‍♂️",	//pouting_man_dark_skin_tone
	"🙎🏻",	//person_with_pouting_face_light_skin_tone
	"🙎🏼",	//person_with_pouting_face_medium_light_skin_tone
	"🙎🏽",	//person_with_pouting_face_medium_skin_tone
	"🙎🏾",	//person_with_pouting_face_medium_dark_skin_tone
	"🙎🏿",	//person_with_pouting_face_dark_skin_tone
	"🙏🏻",	//pray_light_skin_tone
	"🙏🏼",	//pray_medium_light_skin_tone
	"🙏🏽",	//pray_medium_skin_tone
	"🙏🏾",	//pray_medium_dark_skin_tone
	"🙏🏿",	//pray_dark_skin_tone
	"🚣🏻‍♀️",	//woman-rowing-boat_light_skin_tone
	"🚣🏻‍♀️",	//rowing_woman_light_skin_tone
	"🚣🏼‍♀️",	//woman-rowing-boat_medium_light_skin_tone
	"🚣🏼‍♀️",	//rowing_woman_medium_light_skin_tone
	"🚣🏽‍♀️",	//woman-rowing-boat_medium_skin_tone
	"🚣🏽‍♀️",	//rowing_woman_medium_skin_tone
	"🚣🏾‍♀️",	//woman-rowing-boat_medium_dark_skin_tone
	"🚣🏾‍♀️",	//rowing_woman_medium_dark_skin_tone
	"🚣🏿‍♀️",	//woman-rowing-boat_dark_skin_tone
	"🚣🏿‍♀️",	//rowing_woman_dark_skin_tone
	"🚣🏻‍♂️",	//man-rowing-boat_light_skin_tone
	"🚣🏻‍♂️",	//rowing_man_light_skin_tone
	"🚣🏼‍♂️",	//man-rowing-boat_medium_light_skin_tone
	"🚣🏼‍♂️",	//rowing_man_medium_light_skin_tone
	"🚣🏽‍♂️",	//man-rowing-boat_medium_skin_tone
	"🚣🏽‍♂️",	//rowing_man_medium_skin_tone
	"🚣🏾‍♂️",	//man-rowing-boat_medium_dark_skin_tone
	"🚣🏾‍♂️",	//rowing_man_medium_dark_skin_tone
	"🚣🏿‍♂️",	//man-rowing-boat_dark_skin_tone
	"🚣🏿‍♂️",	//rowing_man_dark_skin_tone
	"🚣🏻",	//rowboat_light_skin_tone
	"🚣🏼",	//rowboat_medium_light_skin_tone
	"🚣🏽",	//rowboat_medium_skin_tone
	"🚣🏾",	//rowboat_medium_dark_skin_tone
	"🚣🏿",	//rowboat_dark_skin_tone
	"🚴🏻‍♀️",	//woman-biking_light_skin_tone
	"🚴🏻‍♀️",	//biking_woman_light_skin_tone
	"🚴🏼‍♀️",	//woman-biking_medium_light_skin_tone
	"🚴🏼‍♀️",	//biking_woman_medium_light_skin_tone
	"🚴🏽‍♀️",	//woman-biking_medium_skin_tone
	"🚴🏽‍♀️",	//biking_woman_medium_skin_tone
	"🚴🏾‍♀️",	//woman-biking_medium_dark_skin_tone
	"🚴🏾‍♀️",	//biking_woman_medium_dark_skin_tone
	"🚴🏿‍♀️",	//woman-biking_dark_skin_tone
	"🚴🏿‍♀️",	//biking_woman_dark_skin_tone
	"🚴🏻‍♂️",	//man-biking_light_skin_tone
	"🚴🏻‍♂️",	//biking_man_light_skin_tone
	"🚴🏼‍♂️",	//man-biking_medium_light_skin_tone
	"🚴🏼‍♂️",	//biking_man_medium_light_skin_tone
	"🚴🏽‍♂️",	//man-biking_medium_skin_tone
	"🚴🏽‍♂️",	//biking_man_medium_skin_tone
	"🚴🏾‍♂️",	//man-biking_medium_dark_skin_tone
	"🚴🏾‍♂️",	//biking_man_medium_dark_skin_tone
	"🚴🏿‍♂️",	//man-biking_dark_skin_tone
	"🚴🏿‍♂️",	//biking_man_dark_skin_tone
	"🚴🏻",	//bicyclist_light_skin_tone
	"🚴🏼",	//bicyclist_medium_light_skin_tone
	"🚴🏽",	//bicyclist_medium_skin_tone
	"🚴🏾",	//bicyclist_medium_dark_skin_tone
	"🚴🏿",	//bicyclist_dark_skin_tone
	"🚵🏻‍♀️",	//woman-mountain-biking_light_skin_tone
	"🚵🏻‍♀️",	//mountain_biking_woman_light_skin_tone
	"🚵🏼‍♀️",	//woman-mountain-biking_medium_light_skin_tone
	"🚵🏼‍♀️",	//mountain_biking_woman_medium_light_skin_tone
	"🚵🏽‍♀️",	//woman-mountain-biking_medium_skin_tone
	"🚵🏽‍♀️",	//mountain_biking_woman_medium_skin_tone
	"🚵🏾‍♀️",	//woman-mountain-biking_medium_dark_skin_tone
	"🚵🏾‍♀️",	//mountain_biking_woman_medium_dark_skin_tone
	"🚵🏿‍♀️",	//woman-mountain-biking_dark_skin_tone
	"🚵🏿‍♀️",	//mountain_biking_woman_dark_skin_tone
	"🚵🏻‍♂️",	//man-mountain-biking_light_skin_tone
	"🚵🏻‍♂️",	//mountain_biking_man_light_skin_tone
	"🚵🏼‍♂️",	//man-mountain-biking_medium_light_skin_tone
	"🚵🏼‍♂️",	//mountain_biking_man_medium_light_skin_tone
	"🚵🏽‍♂️",	//man-mountain-biking_medium_skin_tone
	"🚵🏽‍♂️",	//mountain_biking_man_medium_skin_tone
	"🚵🏾‍♂️",	//man-mountain-biking_medium_dark_skin_tone
	"🚵🏾‍♂️",	//mountain_biking_man_medium_dark_skin_tone
	"🚵🏿‍♂️",	//man-mountain-biking_dark_skin_tone
	"🚵🏿‍♂️",	//mountain_biking_man_dark_skin_tone
	"🚵🏻",	//mountain_bicyclist_light_skin_tone
	"🚵🏼",	//mountain_bicyclist_medium_light_skin_tone
	"🚵🏽",	//mountain_bicyclist_medium_skin_tone
	"🚵🏾",	//mountain_bicyclist_medium_dark_skin_tone
	"🚵🏿",	//mountain_bicyclist_dark_skin_tone
	"🚶🏻‍♀️",	//woman-walking_light_skin_tone
	"🚶🏻‍♀️",	//walking_woman_light_skin_tone
	"🚶🏼‍♀️",	//woman-walking_medium_light_skin_tone
	"🚶🏼‍♀️",	//walking_woman_medium_light_skin_tone
	"🚶🏽‍♀️",	//woman-walking_medium_skin_tone
	"🚶🏽‍♀️",	//walking_woman_medium_skin_tone
	"🚶🏾‍♀️",	//woman-walking_medium_dark_skin_tone
	"🚶🏾‍♀️",	//walking_woman_medium_dark_skin_tone
	"🚶🏿‍♀️",	//woman-walking_dark_skin_tone
	"🚶🏿‍♀️",	//walking_woman_dark_skin_tone
	"🚶🏻‍♂️",	//man-walking_light_skin_tone
	"🚶🏻‍♂️",	//walking_man_light_skin_tone
	"🚶🏼‍♂️",	//man-walking_medium_light_skin_tone
	"🚶🏼‍♂️",	//walking_man_medium_light_skin_tone
	"🚶🏽‍♂️",	//man-walking_medium_skin_tone
	"🚶🏽‍♂️",	//walking_man_medium_skin_tone
	"🚶🏾‍♂️",	//man-walking_medium_dark_skin_tone
	"🚶🏾‍♂️",	//walking_man_medium_dark_skin_tone
	"🚶🏿‍♂️",	//man-walking_dark_skin_tone
	"🚶🏿‍♂️",	//walking_man_dark_skin_tone
	"🚶🏻",	//walking_light_skin_tone
	"🚶🏼",	//walking_medium_light_skin_tone
	"🚶🏽",	//walking_medium_skin_tone
	"🚶🏾",	//walking_medium_dark_skin_tone
	"🚶🏿",	//walking_dark_skin_tone
	"🛀🏻",	//bath_light_skin_tone
	"🛀🏼",	//bath_medium_light_skin_tone
	"🛀🏽",	//bath_medium_skin_tone
	"🛀🏾",	//bath_medium_dark_skin_tone
	"🛀🏿",	//bath_dark_skin_tone
	"🛌🏻",	//sleeping_accommodation_light_skin_tone
	"🛌🏼",	//sleeping_accommodation_medium_light_skin_tone
	"🛌🏽",	//sleeping_accommodation_medium_skin_tone
	"🛌🏾",	//sleeping_accommodation_medium_dark_skin_tone
	"🛌🏿",	//sleeping_accommodation_dark_skin_tone
	"🤌🏻",	//pinched_fingers_light_skin_tone
	"🤌🏼",	//pinched_fingers_medium_light_skin_tone
	"🤌🏽",	//pinched_fingers_medium_skin_tone
	"🤌🏾",	//pinched_fingers_medium_dark_skin_tone
	"🤌🏿",	//pinched_fingers_dark_skin_tone
	"🤏🏻",	//pinching_hand_light_skin_tone
	"🤏🏼",	//pinching_hand_medium_light_skin_tone
	"🤏🏽",	//pinching_hand_medium_skin_tone
	"🤏🏾",	//pinching_hand_medium_dark_skin_tone
	"🤏🏿",	//pinching_hand_dark_skin_tone
	"🤘🏻",	//the_horns_light_skin_tone
	"🤘🏻",	//sign_of_the_horns_light_skin_tone
	"🤘🏻",	//metal_light_skin_tone
	"🤘🏼",	//the_horns_medium_light_skin_tone
	"🤘🏼",	//sign_of_the_horns_medium_light_skin_tone
	"🤘🏼",	//metal_medium_light_skin_tone
	"🤘🏽",	//the_horns_medium_skin_tone
	"🤘🏽",	//sign_of_the_horns_medium_skin_tone
	"🤘🏽",	//metal_medium_skin_tone
	"🤘🏾",	//the_horns_medium_dark_skin_tone
	"🤘🏾",	//sign_of_the_horns_medium_dark_skin_tone
	"🤘🏾",	//metal_medium_dark_skin_tone
	"🤘🏿",	//the_horns_dark_skin_tone
	"🤘🏿",	//sign_of_the_horns_dark_skin_tone
	"🤘🏿",	//metal_dark_skin_tone
	"🤙🏻",	//call_me_hand_light_skin_tone
	"🤙🏼",	//call_me_hand_medium_light_skin_tone
	"🤙🏽",	//call_me_hand_medium_skin_tone
	"🤙🏾",	//call_me_hand_medium_dark_skin_tone
	"🤙🏿",	//call_me_hand_dark_skin_tone
	"🤚🏻",	//raised_back_of_hand_light_skin_tone
	"🤚🏼",	//raised_back_of_hand_medium_light_skin_tone
	"🤚🏽",	//raised_back_of_hand_medium_skin_tone
	"🤚🏾",	//raised_back_of_hand_medium_dark_skin_tone
	"🤚🏿",	//raised_back_of_hand_dark_skin_tone
	"🤛🏻",	//left-facing_fist_light_skin_tone
	"🤛🏻",	//fist_left_light_skin_tone
	"🤛🏼",	//left-facing_fist_medium_light_skin_tone
	"🤛🏼",	//fist_left_medium_light_skin_tone
	"🤛🏽",	//left-facing_fist_medium_skin_tone
	"🤛🏽",	//fist_left_medium_skin_tone
	"🤛🏾",	//left-facing_fist_medium_dark_skin_tone
	"🤛🏾",	//fist_left_medium_dark_skin_tone
	"🤛🏿",	//left-facing_fist_dark_skin_tone
	"🤛🏿",	//fist_left_dark_skin_tone
	"🤜🏻",	//right-facing_fist_light_skin_tone
	"🤜🏻",	//fist_right_light_skin_tone
	"🤜🏼",	//right-facing_fist_medium_light_skin_tone
	"🤜🏼",	//fist_right_medium_light_skin_tone
	"🤜🏽",	//right-facing_fist_medium_skin_tone
	"🤜🏽",	//fist_right_medium_skin_tone
	"🤜🏾",	//right-facing_fist_medium_dark_skin_tone
	"🤜🏾",	//fist_right_medium_dark_skin_tone
	"🤜🏿",	//right-facing_fist_dark_skin_tone
	"🤜🏿",	//fist_right_dark_skin_tone
	"🤞🏻",	//crossed_fingers_light_skin_tone
	"🤞🏻",	//hand_with_index_and_middle_fingers_crossed_light_skin_tone
	"🤞🏼",	//crossed_fingers_medium_light_skin_tone
	"🤞🏼",	//hand_with_index_and_middle_fingers_crossed_medium_light_skin_tone
	"🤞🏽",	//crossed_fingers_medium_skin_tone
	"🤞🏽",	//hand_with_index_and_middle_fingers_crossed_medium_skin_tone
	"🤞🏾",	//crossed_fingers_medium_dark_skin_tone
	"🤞🏾",	//hand_with_index_and_middle_fingers_crossed_medium_dark_skin_tone
	"🤞🏿",	//crossed_fingers_dark_skin_tone
	"🤞🏿",	//hand_with_index_and_middle_fingers_crossed_dark_skin_tone
	"🤟🏻",	//i_love_you_hand_sign_light_skin_tone
	"🤟🏼",	//i_love_you_hand_sign_medium_light_skin_tone
	"🤟🏽",	//i_love_you_hand_sign_medium_skin_tone
	"🤟🏾",	//i_love_you_hand_sign_medium_dark_skin_tone
	"🤟🏿",	//i_love_you_hand_sign_dark_skin_tone
	"🤦🏻‍♀️",	//woman-facepalming_light_skin_tone
	"🤦🏻‍♀️",	//woman_facepalming_light_skin_tone
	"🤦🏼‍♀️",	//woman-facepalming_medium_light_skin_tone
	"🤦🏼‍♀️",	//woman_facepalming_medium_light_skin_tone
	"🤦🏽‍♀️",	//woman-facepalming_medium_skin_tone
	"🤦🏽‍♀️",	//woman_facepalming_medium_skin_tone
	"🤦🏾‍♀️",	//woman-facepalming_medium_dark_skin_tone
	"🤦🏾‍♀️",	//woman_facepalming_medium_dark_skin_tone
	"🤦🏿‍♀️",	//woman-facepalming_dark_skin_tone
	"🤦🏿‍♀️",	//woman_facepalming_dark_skin_tone
	"🤦🏻‍♂️",	//man-facepalming_light_skin_tone
	"🤦🏻‍♂️",	//man_facepalming_light_skin_tone
	"🤦🏼‍♂️",	//man-facepalming_medium_light_skin_tone
	"🤦🏼‍♂️",	//man_facepalming_medium_light_skin_tone
	"🤦🏽‍♂️",	//man-facepalming_medium_skin_tone
	"🤦🏽‍♂️",	//man_facepalming_medium_skin_tone
	"🤦🏾‍♂️",	//man-facepalming_medium_dark_skin_tone
	"🤦🏾‍♂️",	//man_facepalming_medium_dark_skin_tone
	"🤦🏿‍♂️",	//man-facepalming_dark_skin_tone
	"🤦🏿‍♂️",	//man_facepalming_dark_skin_tone
	"🤦🏻",	//face_palm_light_skin_tone
	"🤦🏼",	//face_palm_medium_light_skin_tone
	"🤦🏽",	//face_palm_medium_skin_tone
	"🤦🏾",	//face_palm_medium_dark_skin_tone
	"🤦🏿",	//face_palm_dark_skin_tone
	"🤰🏻",	//pregnant_woman_light_skin_tone
	"🤰🏼",	//pregnant_woman_medium_light_skin_tone
	"🤰🏽",	//pregnant_woman_medium_skin_tone
	"🤰🏾",	//pregnant_woman_medium_dark_skin_tone
	"🤰🏿",	//pregnant_woman_dark_skin_tone
	"🤱🏻",	//breast-feeding_light_skin_tone
	"🤱🏼",	//breast-feeding_medium_light_skin_tone
	"🤱🏽",	//breast-feeding_medium_skin_tone
	"🤱🏾",	//breast-feeding_medium_dark_skin_tone
	"🤱🏿",	//breast-feeding_dark_skin_tone
	"🤲🏻",	//palms_up_together_light_skin_tone
	"🤲🏼",	//palms_up_together_medium_light_skin_tone
	"🤲🏽",	//palms_up_together_medium_skin_tone
	"🤲🏾",	//palms_up_together_medium_dark_skin_tone
	"🤲🏿",	//palms_up_together_dark_skin_tone
	"🤳🏻",	//selfie_light_skin_tone
	"🤳🏼",	//selfie_medium_light_skin_tone
	"🤳🏽",	//selfie_medium_skin_tone
	"🤳🏾",	//selfie_medium_dark_skin_tone
	"🤳🏿",	//selfie_dark_skin_tone
	"🤴🏻",	//prince_light_skin_tone
	"🤴🏼",	//prince_medium_light_skin_tone
	"🤴🏽",	//prince_medium_skin_tone
	"🤴🏾",	//prince_medium_dark_skin_tone
	"🤴🏿",	//prince_dark_skin_tone
	"🤵🏻‍♀️",	//woman_in_tuxedo_light_skin_tone
	"🤵🏼‍♀️",	//woman_in_tuxedo_medium_light_skin_tone
	"🤵🏽‍♀️",	//woman_in_tuxedo_medium_skin_tone
	"🤵🏾‍♀️",	//woman_in_tuxedo_medium_dark_skin_tone
	"🤵🏿‍♀️",	//woman_in_tuxedo_dark_skin_tone
	"🤵🏻‍♂️",	//man_in_tuxedo_light_skin_tone
	"🤵🏼‍♂️",	//man_in_tuxedo_medium_light_skin_tone
	"🤵🏽‍♂️",	//man_in_tuxedo_medium_skin_tone
	"🤵🏾‍♂️",	//man_in_tuxedo_medium_dark_skin_tone
	"🤵🏿‍♂️",	//man_in_tuxedo_dark_skin_tone
	"🤵🏻",	//person_in_tuxedo_light_skin_tone
	"🤵🏼",	//person_in_tuxedo_medium_light_skin_tone
	"🤵🏽",	//person_in_tuxedo_medium_skin_tone
	"🤵🏾",	//person_in_tuxedo_medium_dark_skin_tone
	"🤵🏿",	//person_in_tuxedo_dark_skin_tone
	"🤶🏻",	//mrs_claus_light_skin_tone
	"🤶🏻",	//mother_christmas_light_skin_tone
	"🤶🏼",	//mrs_claus_medium_light_skin_tone
	"🤶🏼",	//mother_christmas_medium_light_skin_tone
	"🤶🏽",	//mrs_claus_medium_skin_tone
	"🤶🏽",	//mother_christmas_medium_skin_tone
	"🤶🏾",	//mrs_claus_medium_dark_skin_tone
	"🤶🏾",	//mother_christmas_medium_dark_skin_tone
	"🤶🏿",	//mrs_claus_dark_skin_tone
	"🤶🏿",	//mother_christmas_dark_skin_tone
	"🤷🏻‍♀️",	//woman-shrugging_light_skin_tone
	"🤷🏻‍♀️",	//woman_shrugging_light_skin_tone
	"🤷🏼‍♀️",	//woman-shrugging_medium_light_skin_tone
	"🤷🏼‍♀️",	//woman_shrugging_medium_light_skin_tone
	"🤷🏽‍♀️",	//woman-shrugging_medium_skin_tone
	"🤷🏽‍♀️",	//woman_shrugging_medium_skin_tone
	"🤷🏾‍♀️",	//woman-shrugging_medium_dark_skin_tone
	"🤷🏾‍♀️",	//woman_shrugging_medium_dark_skin_tone
	"🤷🏿‍♀️",	//woman-shrugging_dark_skin_tone
	"🤷🏿‍♀️",	//woman_shrugging_dark_skin_tone
	"🤷🏻‍♂️",	//man-shrugging_light_skin_tone
	"🤷🏻‍♂️",	//man_shrugging_light_skin_tone
	"🤷🏼‍♂️",	//man-shrugging_medium_light_skin_tone
	"🤷🏼‍♂️",	//man_shrugging_medium_light_skin_tone
	"🤷🏽‍♂️",	//man-shrugging_medium_skin_tone
	"🤷🏽‍♂️",	//man_shrugging_medium_skin_tone
	"🤷🏾‍♂️",	//man-shrugging_medium_dark_skin_tone
	"🤷🏾‍♂️",	//man_shrugging_medium_dark_skin_tone
	"🤷🏿‍♂️",	//man-shrugging_dark_skin_tone
	"🤷🏿‍♂️",	//man_shrugging_dark_skin_tone
	"🤷🏻",	//shrug_light_skin_tone
	"🤷🏼",	//shrug_medium_light_skin_tone
	"🤷🏽",	//shrug_medium_skin_tone
	"🤷🏾",	//shrug_medium_dark_skin_tone
	"🤷🏿",	//shrug_dark_skin_tone
	"🤸🏻‍♀️",	//woman-cartwheeling_light_skin_tone
	"🤸🏻‍♀️",	//woman_cartwheeling_light_skin_tone
	"🤸🏼‍♀️",	//woman-cartwheeling_medium_light_skin_tone
	"🤸🏼‍♀️",	//woman_cartwheeling_medium_light_skin_tone
	"🤸🏽‍♀️",	//woman-cartwheeling_medium_skin_tone
	"🤸🏽‍♀️",	//woman_cartwheeling_medium_skin_tone
	"🤸🏾‍♀️",	//woman-cartwheeling_medium_dark_skin_tone
	"🤸🏾‍♀️",	//woman_cartwheeling_medium_dark_skin_tone
	"🤸🏿‍♀️",	//woman-cartwheeling_dark_skin_tone
	"🤸🏿‍♀️",	//woman_cartwheeling_dark_skin_tone
	"🤸🏻‍♂️",	//man-cartwheeling_light_skin_tone
	"🤸🏻‍♂️",	//man_cartwheeling_light_skin_tone
	"🤸🏼‍♂️",	//man-cartwheeling_medium_light_skin_tone
	"🤸🏼‍♂️",	//man_cartwheeling_medium_light_skin_tone
	"🤸🏽‍♂️",	//man-cartwheeling_medium_skin_tone
	"🤸🏽‍♂️",	//man_cartwheeling_medium_skin_tone
	"🤸🏾‍♂️",	//man-cartwheeling_medium_dark_skin_tone
	"🤸🏾‍♂️",	//man_cartwheeling_medium_dark_skin_tone
	"🤸🏿‍♂️",	//man-cartwheeling_dark_skin_tone
	"🤸🏿‍♂️",	//man_cartwheeling_dark_skin_tone
	"🤸🏻",	//person_doing_cartwheel_light_skin_tone
	"🤸🏼",	//person_doing_cartwheel_medium_light_skin_tone
	"🤸🏽",	//person_doing_cartwheel_medium_skin_tone
	"🤸🏾",	//person_doing_cartwheel_medium_dark_skin_tone
	"🤸🏿",	//person_doing_cartwheel_dark_skin_tone
	"🤹🏻‍♀️",	//woman-juggling_light_skin_tone
	"🤹🏻‍♀️",	//woman_juggling_light_skin_tone
	"🤹🏼‍♀️",	//woman-juggling_medium_light_skin_tone
	"🤹🏼‍♀️",	//woman_juggling_medium_light_skin_tone
	"🤹🏽‍♀️",	//woman-juggling_medium_skin_tone
	"🤹🏽‍♀️",	//woman_juggling_medium_skin_tone
	"🤹🏾‍♀️",	//woman-juggling_medium_dark_skin_tone
	"🤹🏾‍♀️",	//woman_juggling_medium_dark_skin_tone
	"🤹🏿‍♀️",	//woman-juggling_dark_skin_tone
	"🤹🏿‍♀️",	//woman_juggling_dark_skin_tone
	"🤹🏻‍♂️",	//man-juggling_light_skin_tone
	"🤹🏻‍♂️",	//man_juggling_light_skin_tone
	"🤹🏼‍♂️",	//man-juggling_medium_light_skin_tone
	"🤹🏼‍♂️",	//man_juggling_medium_light_skin_tone
	"🤹🏽‍♂️",	//man-juggling_medium_skin_tone
	"🤹🏽‍♂️",	//man_juggling_medium_skin_tone
	"🤹🏾‍♂️",	//man-juggling_medium_dark_skin_tone
	"🤹🏾‍♂️",	//man_juggling_medium_dark_skin_tone
	"🤹🏿‍♂️",	//man-juggling_dark_skin_tone
	"🤹🏿‍♂️",	//man_juggling_dark_skin_tone
	"🤹🏻",	//juggling_light_skin_tone
	"🤹🏼",	//juggling_medium_light_skin_tone
	"🤹🏽",	//juggling_medium_skin_tone
	"🤹🏾",	//juggling_medium_dark_skin_tone
	"🤹🏿",	//juggling_dark_skin_tone
	"🤽🏻‍♀️",	//woman-playing-water-polo_light_skin_tone
	"🤽🏻‍♀️",	//woman_playing_water_polo_light_skin_tone
	"🤽🏼‍♀️",	//woman-playing-water-polo_medium_light_skin_tone
	"🤽🏼‍♀️",	//woman_playing_water_polo_medium_light_skin_tone
	"🤽🏽‍♀️",	//woman-playing-water-polo_medium_skin_tone
	"🤽🏽‍♀️",	//woman_playing_water_polo_medium_skin_tone
	"🤽🏾‍♀️",	//woman-playing-water-polo_medium_dark_skin_tone
	"🤽🏾‍♀️",	//woman_playing_water_polo_medium_dark_skin_tone
	"🤽🏿‍♀️",	//woman-playing-water-polo_dark_skin_tone
	"🤽🏿‍♀️",	//woman_playing_water_polo_dark_skin_tone
	"🤽🏻‍♂️",	//man-playing-water-polo_light_skin_tone
	"🤽🏻‍♂️",	//man_playing_water_polo_light_skin_tone
	"🤽🏼‍♂️",	//man-playing-water-polo_medium_light_skin_tone
	"🤽🏼‍♂️",	//man_playing_water_polo_medium_light_skin_tone
	"🤽🏽‍♂️",	//man-playing-water-polo_medium_skin_tone
	"🤽🏽‍♂️",	//man_playing_water_polo_medium_skin_tone
	"🤽🏾‍♂️",	//man-playing-water-polo_medium_dark_skin_tone
	"🤽🏾‍♂️",	//man_playing_water_polo_medium_dark_skin_tone
	"🤽🏿‍♂️",	//man-playing-water-polo_dark_skin_tone
	"🤽🏿‍♂️",	//man_playing_water_polo_dark_skin_tone
	"🤽🏻",	//water_polo_light_skin_tone
	"🤽🏼",	//water_polo_medium_light_skin_tone
	"🤽🏽",	//water_polo_medium_skin_tone
	"🤽🏾",	//water_polo_medium_dark_skin_tone
	"🤽🏿",	//water_polo_dark_skin_tone
	"🤾🏻‍♀️",	//woman-playing-handball_light_skin_tone
	"🤾🏻‍♀️",	//woman_playing_handball_light_skin_tone
	"🤾🏼‍♀️",	//woman-playing-handball_medium_light_skin_tone
	"🤾🏼‍♀️",	//woman_playing_handball_medium_light_skin_tone
	"🤾🏽‍♀️",	//woman-playing-handball_medium_skin_tone
	"🤾🏽‍♀️",	//woman_playing_handball_medium_skin_tone
	"🤾🏾‍♀️",	//woman-playing-handball_medium_dark_skin_tone
	"🤾🏾‍♀️",	//woman_playing_handball_medium_dark_skin_tone
	"🤾🏿‍♀️",	//woman-playing-handball_dark_skin_tone
	"🤾🏿‍♀️",	//woman_playing_handball_dark_skin_tone
	"🤾🏻‍♂️",	//man-playing-handball_light_skin_tone
	"🤾🏻‍♂️",	//man_playing_handball_light_skin_tone
	"🤾🏼‍♂️",	//man-playing-handball_medium_light_skin_tone
	"🤾🏼‍♂️",	//man_playing_handball_medium_light_skin_tone
	"🤾🏽‍♂️",	//man-playing-handball_medium_skin_tone
	"🤾🏽‍♂️",	//man_playing_handball_medium_skin_tone
	"🤾🏾‍♂️",	//man-playing-handball_medium_dark_skin_tone
	"🤾🏾‍♂️",	//man_playing_handball_medium_dark_skin_tone
	"🤾🏿‍♂️",	//man-playing-handball_dark_skin_tone
	"🤾🏿‍♂️",	//man_playing_handball_dark_skin_tone
	"🤾🏻",	//handball_light_skin_tone
	"🤾🏼",	//handball_medium_light_skin_tone
	"🤾🏽",	//handball_medium_skin_tone
	"🤾🏾",	//handball_medium_dark_skin_tone
	"🤾🏿",	//handball_dark_skin_tone
	"🥷🏻",	//ninja_light_skin_tone
	"🥷🏼",	//ninja_medium_light_skin_tone
	"🥷🏽",	//ninja_medium_skin_tone
	"🥷🏾",	//ninja_medium_dark_skin_tone
	"🥷🏿",	//ninja_dark_skin_tone
	"🦵🏻",	//leg_light_skin_tone
	"🦵🏼",	//leg_medium_light_skin_tone
	"🦵🏽",	//leg_medium_skin_tone
	"🦵🏾",	//leg_medium_dark_skin_tone
	"🦵🏿",	//leg_dark_skin_tone
	"🦶🏻",	//foot_light_skin_tone
	"🦶🏼",	//foot_medium_light_skin_tone
	"🦶🏽",	//foot_medium_skin_tone
	"🦶🏾",	//foot_medium_dark_skin_tone
	"🦶🏿",	//foot_dark_skin_tone
	"🦸🏻‍♀️",	//female_superhero_light_skin_tone
	"🦸🏼‍♀️",	//female_superhero_medium_light_skin_tone
	"🦸🏽‍♀️",	//female_superhero_medium_skin_tone
	"🦸🏾‍♀️",	//female_superhero_medium_dark_skin_tone
	"🦸🏿‍♀️",	//female_superhero_dark_skin_tone
	"🦸🏻‍♂️",	//male_superhero_light_skin_tone
	"🦸🏼‍♂️",	//male_superhero_medium_light_skin_tone
	"🦸🏽‍♂️",	//male_superhero_medium_skin_tone
	"🦸🏾‍♂️",	//male_superhero_medium_dark_skin_tone
	"🦸🏿‍♂️",	//male_superhero_dark_skin_tone
	"🦸🏻",	//superhero_light_skin_tone
	"🦸🏼",	//superhero_medium_light_skin_tone
	"🦸🏽",	//superhero_medium_skin_tone
	"🦸🏾",	//superhero_medium_dark_skin_tone
	"🦸🏿",	//superhero_dark_skin_tone
	"🦹🏻‍♀️",	//female_supervillain_light_skin_tone
	"🦹🏼‍♀️",	//female_supervillain_medium_light_skin_tone
	"🦹🏽‍♀️",	//female_supervillain_medium_skin_tone
	"🦹🏾‍♀️",	//female_supervillain_medium_dark_skin_tone
	"🦹🏿‍♀️",	//female_supervillain_dark_skin_tone
	"🦹🏻‍♂️",	//male_supervillain_light_skin_tone
	"🦹🏼‍♂️",	//male_supervillain_medium_light_skin_tone
	"🦹🏽‍♂️",	//male_supervillain_medium_skin_tone
	"🦹🏾‍♂️",	//male_supervillain_medium_dark_skin_tone
	"🦹🏿‍♂️",	//male_supervillain_dark_skin_tone
	"🦹🏻",	//supervillain_light_skin_tone
	"🦹🏼",	//supervillain_medium_light_skin_tone
	"🦹🏽",	//supervillain_medium_skin_tone
	"🦹🏾",	//supervillain_medium_dark_skin_tone
	"🦹🏿",	//supervillain_dark_skin_tone
	"🦻🏻",	//ear_with_hearing_aid_light_skin_tone
	"🦻🏼",	//ear_with_hearing_aid_medium_light_skin_tone
	"🦻🏽",	//ear_with_hearing_aid_medium_skin_tone
	"🦻🏾",	//ear_with_hearing_aid_medium_dark_skin_tone
	"🦻🏿",	//ear_with_hearing_aid_dark_skin_tone
	"🧍🏻‍♀️",	//woman_standing_light_skin_tone
	"🧍🏼‍♀️",	//woman_standing_medium_light_skin_tone
	"🧍🏽‍♀️",	//woman_standing_medium_skin_tone
	"🧍🏾‍♀️",	//woman_standing_medium_dark_skin_tone
	"🧍🏿‍♀️",	//woman_standing_dark_skin_tone
	"🧍🏻‍♂️",	//man_standing_light_skin_tone
	"🧍🏼‍♂️",	//man_standing_medium_light_skin_tone
	"🧍🏽‍♂️",	//man_standing_medium_skin_tone
	"🧍🏾‍♂️",	//man_standing_medium_dark_skin_tone
	"🧍🏿‍♂️",	//man_standing_dark_skin_tone
	"🧍🏻",	//standing_person_light_skin_tone
	"🧍🏼",	//standing_person_medium_light_skin_tone
	"🧍🏽",	//standing_person_medium_skin_tone
	"🧍🏾",	//standing_person_medium_dark_skin_tone
	"🧍🏿",	//standing_person_dark_skin_tone
	"🧎🏻‍♀️",	//woman_kneeling_light_skin_tone
	"🧎🏼‍♀️",	//woman_kneeling_medium_light_skin_tone
	"🧎🏽‍♀️",	//woman_kneeling_medium_skin_tone
	"🧎🏾‍♀️",	//woman_kneeling_medium_dark_skin_tone
	"🧎🏿‍♀️",	//woman_kneeling_dark_skin_tone
	"🧎🏻‍♂️",	//man_kneeling_light_skin_tone
	"🧎🏼‍♂️",	//man_kneeling_medium_light_skin_tone
	"🧎🏽‍♂️",	//man_kneeling_medium_skin_tone
	"🧎🏾‍♂️",	//man_kneeling_medium_dark_skin_tone
	"🧎🏿‍♂️",	//man_kneeling_dark_skin_tone
	"🧎🏻",	//kneeling_person_light_skin_tone
	"🧎🏼",	//kneeling_person_medium_light_skin_tone
	"🧎🏽",	//kneeling_person_medium_skin_tone
	"🧎🏾",	//kneeling_person_medium_dark_skin_tone
	"🧎🏿",	//kneeling_person_dark_skin_tone
	"🧏🏻‍♀️",	//deaf_woman_light_skin_tone
	"🧏🏼‍♀️",	//deaf_woman_medium_light_skin_tone
	"🧏🏽‍♀️",	//deaf_woman_medium_skin_tone
	"🧏🏾‍♀️",	//deaf_woman_medium_dark_skin_tone
	"🧏🏿‍♀️",	//deaf_woman_dark_skin_tone
	"🧏🏻‍♂️",	//deaf_man_light_skin_tone
	"🧏🏼‍♂️",	//deaf_man_medium_light_skin_tone
	"🧏🏽‍♂️",	//deaf_man_medium_skin_tone
	"🧏🏾‍♂️",	//deaf_man_medium_dark_skin_tone
	"🧏🏿‍♂️",	//deaf_man_dark_skin_tone
	"🧏🏻",	//deaf_person_light_skin_tone
	"🧏🏼",	//deaf_person_medium_light_skin_tone
	"🧏🏽",	//deaf_person_medium_skin_tone
	"🧏🏾",	//deaf_person_medium_dark_skin_tone
	"🧏🏿",	//deaf_person_dark_skin_tone
	"🧑🏻‍🌾",	//farmer_light_skin_tone
	"🧑🏼‍🌾",	//farmer_medium_light_skin_tone
	"🧑🏽‍🌾",	//farmer_medium_skin_tone
	"🧑🏾‍🌾",	//farmer_medium_dark_skin_tone
	"🧑🏿‍🌾",	//farmer_dark_skin_tone
	"🧑🏻‍🍳",	//cook_light_skin_tone
	"🧑🏼‍🍳",	//cook_medium_light_skin_tone
	"🧑🏽‍🍳",	//cook_medium_skin_tone
	"🧑🏾‍🍳",	//cook_medium_dark_skin_tone
	"🧑🏿‍🍳",	//cook_dark_skin_tone
	"🧑🏻‍🍼",	//person_feeding_baby_light_skin_tone
	"🧑🏼‍🍼",	//person_feeding_baby_medium_light_skin_tone
	"🧑🏽‍🍼",	//person_feeding_baby_medium_skin_tone
	"🧑🏾‍🍼",	//person_feeding_baby_medium_dark_skin_tone
	"🧑🏿‍🍼",	//person_feeding_baby_dark_skin_tone
	"🧑🏻‍🎄",	//mx_claus_light_skin_tone
	"🧑🏼‍🎄",	//mx_claus_medium_light_skin_tone
	"🧑🏽‍🎄",	//mx_claus_medium_skin_tone
	"🧑🏾‍🎄",	//mx_claus_medium_dark_skin_tone
	"🧑🏿‍🎄",	//mx_claus_dark_skin_tone
	"🧑🏻‍🎓",	//student_light_skin_tone
	"🧑🏼‍🎓",	//student_medium_light_skin_tone
	"🧑🏽‍🎓",	//student_medium_skin_tone
	"🧑🏾‍🎓",	//student_medium_dark_skin_tone
	"🧑🏿‍🎓",	//student_dark_skin_tone
	"🧑🏻‍🎤",	//singer_light_skin_tone
	"🧑🏼‍🎤",	//singer_medium_light_skin_tone
	"🧑🏽‍🎤",	//singer_medium_skin_tone
	"🧑🏾‍🎤",	//singer_medium_dark_skin_tone
	"🧑🏿‍🎤",	//singer_dark_skin_tone
	"🧑🏻‍🎨",	//artist_light_skin_tone
	"🧑🏼‍🎨",	//artist_medium_light_skin_tone
	"🧑🏽‍🎨",	//artist_medium_skin_tone
	"🧑🏾‍🎨",	//artist_medium_dark_skin_tone
	"🧑🏿‍🎨",	//artist_dark_skin_tone
	"🧑🏻‍🏫",	//teacher_light_skin_tone
	"🧑🏼‍🏫",	//teacher_medium_light_skin_tone
	"🧑🏽‍🏫",	//teacher_medium_skin_tone
	"🧑🏾‍🏫",	//teacher_medium_dark_skin_tone
	"🧑🏿‍🏫",	//teacher_dark_skin_tone
	"🧑🏻‍🏭",	//factory_worker_light_skin_tone
	"🧑🏼‍🏭",	//factory_worker_medium_light_skin_tone
	"🧑🏽‍🏭",	//factory_worker_medium_skin_tone
	"🧑🏾‍🏭",	//factory_worker_medium_dark_skin_tone
	"🧑🏿‍🏭",	//factory_worker_dark_skin_tone
	"🧑🏻‍💻",	//technologist_light_skin_tone
	"🧑🏼‍💻",	//technologist_medium_light_skin_tone
	"🧑🏽‍💻",	//technologist_medium_skin_tone
	"🧑🏾‍💻",	//technologist_medium_dark_skin_tone
	"🧑🏿‍💻",	//technologist_dark_skin_tone
	"🧑🏻‍💼",	//office_worker_light_skin_tone
	"🧑🏼‍💼",	//office_worker_medium_light_skin_tone
	"🧑🏽‍💼",	//office_worker_medium_skin_tone
	"🧑🏾‍💼",	//office_worker_medium_dark_skin_tone
	"🧑🏿‍💼",	//office_worker_dark_skin_tone
	"🧑🏻‍🔧",	//mechanic_light_skin_tone
	"🧑🏼‍🔧",	//mechanic_medium_light_skin_tone
	"🧑🏽‍🔧",	//mechanic_medium_skin_tone
	"🧑🏾‍🔧",	//mechanic_medium_dark_skin_tone
	"🧑🏿‍🔧",	//mechanic_dark_skin_tone
	"🧑🏻‍🔬",	//scientist_light_skin_tone
	"🧑🏼‍🔬",	//scientist_medium_light_skin_tone
	"🧑🏽‍🔬",	//scientist_medium_skin_tone
	"🧑🏾‍🔬",	//scientist_medium_dark_skin_tone
	"🧑🏿‍🔬",	//scientist_dark_skin_tone
	"🧑🏻‍🚀",	//astronaut_light_skin_tone
	"🧑🏼‍🚀",	//astronaut_medium_light_skin_tone
	"🧑🏽‍🚀",	//astronaut_medium_skin_tone
	"🧑🏾‍🚀",	//astronaut_medium_dark_skin_tone
	"🧑🏿‍🚀",	//astronaut_dark_skin_tone
	"🧑🏻‍🚒",	//firefighter_light_skin_tone
	"🧑🏼‍🚒",	//firefighter_medium_light_skin_tone
	"🧑🏽‍🚒",	//firefighter_medium_skin_tone
	"🧑🏾‍🚒",	//firefighter_medium_dark_skin_tone
	"🧑🏿‍🚒",	//firefighter_dark_skin_tone
	"🧑🏻‍🤝‍🧑🏻",	//people_holding_hands_light_skin_tone_light_skin_tone
	"🧑🏻‍🤝‍🧑🏼",	//people_holding_hands_light_skin_tone_medium_light_skin_tone
	"🧑🏻‍🤝‍🧑🏽",	//people_holding_hands_light_skin_tone_medium_skin_tone
	"🧑🏻‍🤝‍🧑🏾",	//people_holding_hands_light_skin_tone_medium_dark_skin_tone
	"🧑🏻‍🤝‍🧑🏿",	//people_holding_hands_light_skin_tone_dark_skin_tone
	"🧑🏼‍🤝‍🧑🏻",	//people_holding_hands_medium_light_skin_tone_light_skin_tone
	"🧑🏼‍🤝‍🧑🏼",	//people_holding_hands_medium_light_skin_tone_medium_light_skin_tone
	"🧑🏼‍🤝‍🧑🏽",	//people_holding_hands_medium_light_skin_tone_medium_skin_tone
	"🧑🏼‍🤝‍🧑🏾",	//people_holding_hands_medium_light_skin_tone_medium_dark_skin_tone
	"🧑🏼‍🤝‍🧑🏿",	//people_holding_hands_medium_light_skin_tone_dark_skin_tone
	"🧑🏽‍🤝‍🧑🏻",	//people_holding_hands_medium_skin_tone_light_skin_tone
	"🧑🏽‍🤝‍🧑🏼",	//people_holding_hands_medium_skin_tone_medium_light_skin_tone
	"🧑🏽‍🤝‍🧑🏽",	//people_holding_hands_medium_skin_tone_medium_skin_tone
	"🧑🏽‍🤝‍🧑🏾",	//people_holding_hands_medium_skin_tone_medium_dark_skin_tone
	"🧑🏽‍🤝‍🧑🏿",	//people_holding_hands_medium_skin_tone_dark_skin_tone
	"🧑🏾‍🤝‍🧑🏻",	//people_holding_hands_medium_dark_skin_tone_light_skin_tone
	"🧑🏾‍🤝‍🧑🏼",	//people_holding_hands_medium_dark_skin_tone_medium_light_skin_tone
	"🧑🏾‍🤝‍🧑🏽",	//people_holding_hands_medium_dark_skin_tone_medium_skin_tone
	"🧑🏾‍🤝‍🧑🏾",	//people_holding_hands_medium_dark_skin_tone_medium_dark_skin_tone
	"🧑🏾‍🤝‍🧑🏿",	//people_holding_hands_medium_dark_skin_tone_dark_skin_tone
	"🧑🏿‍🤝‍🧑🏻",	//people_holding_hands_dark_skin_tone_light_skin_tone
	"🧑🏿‍🤝‍🧑🏼",	//people_holding_hands_dark_skin_tone_medium_light_skin_tone
	"🧑🏿‍🤝‍🧑🏽",	//people_holding_hands_dark_skin_tone_medium_skin_tone
	"🧑🏿‍🤝‍🧑🏾",	//people_holding_hands_dark_skin_tone_medium_dark_skin_tone
	"🧑🏿‍🤝‍🧑🏿",	//people_holding_hands_dark_skin_tone_dark_skin_tone
	"🧑🏻‍🦯",	//person_with_probing_cane_light_skin_tone
	"🧑🏼‍🦯",	//person_with_probing_cane_medium_light_skin_tone
	"🧑🏽‍🦯",	//person_with_probing_cane_medium_skin_tone
	"🧑🏾‍🦯",	//person_with_probing_cane_medium_dark_skin_tone
	"🧑🏿‍🦯",	//person_with_probing_cane_dark_skin_tone
	"🧑🏻‍🦰",	//red_haired_person_light_skin_tone
	"🧑🏼‍🦰",	//red_haired_person_medium_light_skin_tone
	"🧑🏽‍🦰",	//red_haired_person_medium_skin_tone
	"🧑🏾‍🦰",	//red_haired_person_medium_dark_skin_tone
	"🧑🏿‍🦰",	//red_haired_person_dark_skin_tone
	"🧑🏻‍🦱",	//curly_haired_person_light_skin_tone
	"🧑🏼‍🦱",	//curly_haired_person_medium_light_skin_tone
	"🧑🏽‍🦱",	//curly_haired_person_medium_skin_tone
	"🧑🏾‍🦱",	//curly_haired_person_medium_dark_skin_tone
	"🧑🏿‍🦱",	//curly_haired_person_dark_skin_tone
	"🧑🏻‍🦲",	//bald_person_light_skin_tone
	"🧑🏼‍🦲",	//bald_person_medium_light_skin_tone
	"🧑🏽‍🦲",	//bald_person_medium_skin_tone
	"🧑🏾‍🦲",	//bald_person_medium_dark_skin_tone
	"🧑🏿‍🦲",	//bald_person_dark_skin_tone
	"🧑🏻‍🦳",	//white_haired_person_light_skin_tone
	"🧑🏼‍🦳",	//white_haired_person_medium_light_skin_tone
	"🧑🏽‍🦳",	//white_haired_person_medium_skin_tone
	"🧑🏾‍🦳",	//white_haired_person_medium_dark_skin_tone
	"🧑🏿‍🦳",	//white_haired_person_dark_skin_tone
	"🧑🏻‍🦼",	//person_in_motorized_wheelchair_light_skin_tone
	"🧑🏼‍🦼",	//person_in_motorized_wheelchair_medium_light_skin_tone
	"🧑🏽‍🦼",	//person_in_motorized_wheelchair_medium_skin_tone
	"🧑🏾‍🦼",	//person_in_motorized_wheelchair_medium_dark_skin_tone
	"🧑🏿‍🦼",	//person_in_motorized_wheelchair_dark_skin_tone
	"🧑🏻‍🦽",	//person_in_manual_wheelchair_light_skin_tone
	"🧑🏼‍🦽",	//person_in_manual_wheelchair_medium_light_skin_tone
	"🧑🏽‍🦽",	//person_in_manual_wheelchair_medium_skin_tone
	"🧑🏾‍🦽",	//person_in_manual_wheelchair_medium_dark_skin_tone
	"🧑🏿‍🦽",	//person_in_manual_wheelchair_dark_skin_tone
	"🧑🏻‍⚕️",	//health_worker_light_skin_tone
	"🧑🏻‍⚕️",	//doctor_light_skin_tone
	"🧑🏼‍⚕️",	//health_worker_medium_light_skin_tone
	"🧑🏼‍⚕️",	//doctor_medium_light_skin_tone
	"🧑🏽‍⚕️",	//health_worker_medium_skin_tone
	"🧑🏽‍⚕️",	//doctor_medium_skin_tone
	"🧑🏾‍⚕️",	//health_worker_medium_dark_skin_tone
	"🧑🏾‍⚕️",	//doctor_medium_dark_skin_tone
	"🧑🏿‍⚕️",	//health_worker_dark_skin_tone
	"🧑🏿‍⚕️",	//doctor_dark_skin_tone
	"🧑🏻‍⚖️",	//judge_light_skin_tone
	"🧑🏼‍⚖️",	//judge_medium_light_skin_tone
	"🧑🏽‍⚖️",	//judge_medium_skin_tone
	"🧑🏾‍⚖️",	//judge_medium_dark_skin_tone
	"🧑🏿‍⚖️",	//judge_dark_skin_tone
	"🧑🏻‍✈️",	//pilot_light_skin_tone
	"🧑🏼‍✈️",	//pilot_medium_light_skin_tone
	"🧑🏽‍✈️",	//pilot_medium_skin_tone
	"🧑🏾‍✈️",	//pilot_medium_dark_skin_tone
	"🧑🏿‍✈️",	//pilot_dark_skin_tone
	"🧑🏻",	//adult_light_skin_tone
	"🧑🏼",	//adult_medium_light_skin_tone
	"🧑🏽",	//adult_medium_skin_tone
	"🧑🏾",	//adult_medium_dark_skin_tone
	"🧑🏿",	//adult_dark_skin_tone
	"🧒🏻",	//child_light_skin_tone
	"🧒🏼",	//child_medium_light_skin_tone
	"🧒🏽",	//child_medium_skin_tone
	"🧒🏾",	//child_medium_dark_skin_tone
	"🧒🏿",	//child_dark_skin_tone
	"🧓🏻",	//older_adult_light_skin_tone
	"🧓🏼",	//older_adult_medium_light_skin_tone
	"🧓🏽",	//older_adult_medium_skin_tone
	"🧓🏾",	//older_adult_medium_dark_skin_tone
	"🧓🏿",	//older_adult_dark_skin_tone
	"🧔🏻",	//bearded_person_light_skin_tone
	"🧔🏼",	//bearded_person_medium_light_skin_tone
	"🧔🏽",	//bearded_person_medium_skin_tone
	"🧔🏾",	//bearded_person_medium_dark_skin_tone
	"🧔🏿",	//bearded_person_dark_skin_tone
	"🧕🏻",	//person_with_headscarf_light_skin_tone
	"🧕🏼",	//person_with_headscarf_medium_light_skin_tone
	"🧕🏽",	//person_with_headscarf_medium_skin_tone
	"🧕🏾",	//person_with_headscarf_medium_dark_skin_tone
	"🧕🏿",	//person_with_headscarf_dark_skin_tone
	"🧖🏻‍♀️",	//woman_in_steamy_room_light_skin_tone
	"🧖🏼‍♀️",	//woman_in_steamy_room_medium_light_skin_tone
	"🧖🏽‍♀️",	//woman_in_steamy_room_medium_skin_tone
	"🧖🏾‍♀️",	//woman_in_steamy_room_medium_dark_skin_tone
	"🧖🏿‍♀️",	//woman_in_steamy_room_dark_skin_tone
	"🧖🏻‍♂️",	//man_in_steamy_room_light_skin_tone
	"🧖🏼‍♂️",	//man_in_steamy_room_medium_light_skin_tone
	"🧖🏽‍♂️",	//man_in_steamy_room_medium_skin_tone
	"🧖🏾‍♂️",	//man_in_steamy_room_medium_dark_skin_tone
	"🧖🏿‍♂️",	//man_in_steamy_room_dark_skin_tone
	"🧖🏻",	//person_in_steamy_room_light_skin_tone
	"🧖🏼",	//person_in_steamy_room_medium_light_skin_tone
	"🧖🏽",	//person_in_steamy_room_medium_skin_tone
	"🧖🏾",	//person_in_steamy_room_medium_dark_skin_tone
	"🧖🏿",	//person_in_steamy_room_dark_skin_tone
	"🧗🏻‍♀️",	//woman_climbing_light_skin_tone
	"🧗🏼‍♀️",	//woman_climbing_medium_light_skin_tone
	"🧗🏽‍♀️",	//woman_climbing_medium_skin_tone
	"🧗🏾‍♀️",	//woman_climbing_medium_dark_skin_tone
	"🧗🏿‍♀️",	//woman_climbing_dark_skin_tone
	"🧗🏻‍♂️",	//man_climbing_light_skin_tone
	"🧗🏼‍♂️",	//man_climbing_medium_light_skin_tone
	"🧗🏽‍♂️",	//man_climbing_medium_skin_tone
	"🧗🏾‍♂️",	//man_climbing_medium_dark_skin_tone
	"🧗🏿‍♂️",	//man_climbing_dark_skin_tone
	"🧗🏻",	//person_climbing_light_skin_tone
	"🧗🏼",	//person_climbing_medium_light_skin_tone
	"🧗🏽",	//person_climbing_medium_skin_tone
	"🧗🏾",	//person_climbing_medium_dark_skin_tone
	"🧗🏿",	//person_climbing_dark_skin_tone
	"🧘🏻‍♀️",	//woman_in_lotus_position_light_skin_tone
	"🧘🏼‍♀️",	//woman_in_lotus_position_medium_light_skin_tone
	"🧘🏽‍♀️",	//woman_in_lotus_position_medium_skin_tone
	"🧘🏾‍♀️",	//woman_in_lotus_position_medium_dark_skin_tone
	"🧘🏿‍♀️",	//woman_in_lotus_position_dark_skin_tone
	"🧘🏻‍♂️",	//man_in_lotus_position_light_skin_tone
	"🧘🏼‍♂️",	//man_in_lotus_position_medium_light_skin_tone
	"🧘🏽‍♂️",	//man_in_lotus_position_medium_skin_tone
	"🧘🏾‍♂️",	//man_in_lotus_position_medium_dark_skin_tone
	"🧘🏿‍♂️",	//man_in_lotus_position_dark_skin_tone
	"🧘🏻",	//person_in_lotus_position_light_skin_tone
	"🧘🏼",	//person_in_lotus_position_medium_light_skin_tone
	"🧘🏽",	//person_in_lotus_position_medium_skin_tone
	"🧘🏾",	//person_in_lotus_position_medium_dark_skin_tone
	"🧘🏿",	//person_in_lotus_position_dark_skin_tone
	"🧙🏻‍♀️",	//female_mage_light_skin_tone
	"🧙🏼‍♀️",	//female_mage_medium_light_skin_tone
	"🧙🏽‍♀️",	//female_mage_medium_skin_tone
	"🧙🏾‍♀️",	//female_mage_medium_dark_skin_tone
	"🧙🏿‍♀️",	//female_mage_dark_skin_tone
	"🧙🏻‍♂️",	//male_mage_light_skin_tone
	"🧙🏼‍♂️",	//male_mage_medium_light_skin_tone
	"🧙🏽‍♂️",	//male_mage_medium_skin_tone
	"🧙🏾‍♂️",	//male_mage_medium_dark_skin_tone
	"🧙🏿‍♂️",	//male_mage_dark_skin_tone
	"🧙🏻",	//mage_light_skin_tone
	"🧙🏼",	//mage_medium_light_skin_tone
	"🧙🏽",	//mage_medium_skin_tone
	"🧙🏾",	//mage_medium_dark_skin_tone
	"🧙🏿",	//mage_dark_skin_tone
	"🧚🏻‍♀️",	//female_fairy_light_skin_tone
	"🧚🏼‍♀️",	//female_fairy_medium_light_skin_tone
	"🧚🏽‍♀️",	//female_fairy_medium_skin_tone
	"🧚🏾‍♀️",	//female_fairy_medium_dark_skin_tone
	"🧚🏿‍♀️",	//female_fairy_dark_skin_tone
	"🧚🏻‍♂️",	//male_fairy_light_skin_tone
	"🧚🏼‍♂️",	//male_fairy_medium_light_skin_tone
	"🧚🏽‍♂️",	//male_fairy_medium_skin_tone
	"🧚🏾‍♂️",	//male_fairy_medium_dark_skin_tone
	"🧚🏿‍♂️",	//male_fairy_dark_skin_tone
	"🧚🏻",	//fairy_light_skin_tone
	"🧚🏼",	//fairy_medium_light_skin_tone
	"🧚🏽",	//fairy_medium_skin_tone
	"🧚🏾",	//fairy_medium_dark_skin_tone
	"🧚🏿",	//fairy_dark_skin_tone
	"🧛🏻‍♀️",	//female_vampire_light_skin_tone
	"🧛🏼‍♀️",	//female_vampire_medium_light_skin_tone
	"🧛🏽‍♀️",	//female_vampire_medium_skin_tone
	"🧛🏾‍♀️",	//female_vampire_medium_dark_skin_tone
	"🧛🏿‍♀️",	//female_vampire_dark_skin_tone
	"🧛🏻‍♂️",	//male_vampire_light_skin_tone
	"🧛🏼‍♂️",	//male_vampire_medium_light_skin_tone
	"🧛🏽‍♂️",	//male_vampire_medium_skin_tone
	"🧛🏾‍♂️",	//male_vampire_medium_dark_skin_tone
	"🧛🏿‍♂️",	//male_vampire_dark_skin_tone
	"🧛🏻",	//vampire_light_skin_tone
	"🧛🏼",	//vampire_medium_light_skin_tone
	"🧛🏽",	//vampire_medium_skin_tone
	"🧛🏾",	//vampire_medium_dark_skin_tone
	"🧛🏿",	//vampire_dark_skin_tone
	"🧜🏻‍♀️",	//mermaid_light_skin_tone
	"🧜🏼‍♀️",	//mermaid_medium_light_skin_tone
	"🧜🏽‍♀️",	//mermaid_medium_skin_tone
	"🧜🏾‍♀️",	//mermaid_medium_dark_skin_tone
	"🧜🏿‍♀️",	//mermaid_dark_skin_tone
	"🧜🏻‍♂️",	//merman_light_skin_tone
	"🧜🏼‍♂️",	//merman_medium_light_skin_tone
	"🧜🏽‍♂️",	//merman_medium_skin_tone
	"🧜🏾‍♂️",	//merman_medium_dark_skin_tone
	"🧜🏿‍♂️",	//merman_dark_skin_tone
	"🧜🏻",	//merperson_light_skin_tone
	"🧜🏼",	//merperson_medium_light_skin_tone
	"🧜🏽",	//merperson_medium_skin_tone
	"🧜🏾",	//merperson_medium_dark_skin_tone
	"🧜🏿",	//merperson_dark_skin_tone
	"🧝🏻‍♀️",	//female_elf_light_skin_tone
	"🧝🏼‍♀️",	//female_elf_medium_light_skin_tone
	"🧝🏽‍♀️",	//female_elf_medium_skin_tone
	"🧝🏾‍♀️",	//female_elf_medium_dark_skin_tone
	"🧝🏿‍♀️",	//female_elf_dark_skin_tone
	"🧝🏻‍♂️",	//male_elf_light_skin_tone
	"🧝🏼‍♂️",	//male_elf_medium_light_skin_tone
	"🧝🏽‍♂️",	//male_elf_medium_skin_tone
	"🧝🏾‍♂️",	//male_elf_medium_dark_skin_tone
	"🧝🏿‍♂️",	//male_elf_dark_skin_tone
	"🧝🏻",	//elf_light_skin_tone
	"🧝🏼",	//elf_medium_light_skin_tone
	"🧝🏽",	//elf_medium_skin_tone
	"🧝🏾",	//elf_medium_dark_skin_tone
	"🧝🏿",	//elf_dark_skin_tone
	"☝🏻",	//point_up_light_skin_tone
	"☝🏼",	//point_up_medium_light_skin_tone
	"☝🏽",	//point_up_medium_skin_tone
	"☝🏾",	//point_up_medium_dark_skin_tone
	"☝🏿",	//point_up_dark_skin_tone
	"⛹🏻‍♀️",	//woman-bouncing-ball_light_skin_tone
	"⛹🏻‍♀️",	//basketball_woman_light_skin_tone
	"⛹🏼‍♀️",	//woman-bouncing-ball_medium_light_skin_tone
	"⛹🏼‍♀️",	//basketball_woman_medium_light_skin_tone
	"⛹🏽‍♀️",	//woman-bouncing-ball_medium_skin_tone
	"⛹🏽‍♀️",	//basketball_woman_medium_skin_tone
	"⛹🏾‍♀️",	//woman-bouncing-ball_medium_dark_skin_tone
	"⛹🏾‍♀️",	//basketball_woman_medium_dark_skin_tone
	"⛹🏿‍♀️",	//woman-bouncing-ball_dark_skin_tone
	"⛹🏿‍♀️",	//basketball_woman_dark_skin_tone
	"⛹🏻‍♂️",	//man-bouncing-ball_light_skin_tone
	"⛹🏻‍♂️",	//basketball_man_light_skin_tone
	"⛹🏼‍♂️",	//man-bouncing-ball_medium_light_skin_tone
	"⛹🏼‍♂️",	//basketball_man_medium_light_skin_tone
	"⛹🏽‍♂️",	//man-bouncing-ball_medium_skin_tone
	"⛹🏽‍♂️",	//basketball_man_medium_skin_tone
	"⛹🏾‍♂️",	//man-bouncing-ball_medium_dark_skin_tone
	"⛹🏾‍♂️",	//basketball_man_medium_dark_skin_tone
	"⛹🏿‍♂️",	//man-bouncing-ball_dark_skin_tone
	"⛹🏿‍♂️",	//basketball_man_dark_skin_tone
	"⛹🏻",	//person_with_ball_light_skin_tone
	"⛹🏼",	//person_with_ball_medium_light_skin_tone
	"⛹🏽",	//person_with_ball_medium_skin_tone
	"⛹🏾",	//person_with_ball_medium_dark_skin_tone
	"⛹🏿",	//person_with_ball_dark_skin_tone
	"✊🏻",	//fist_light_skin_tone
	"✊🏻",	//fist_raised_light_skin_tone
	"✊🏼",	//fist_medium_light_skin_tone
	"✊🏼",	//fist_raised_medium_light_skin_tone
	"✊🏽",	//fist_medium_skin_tone
	"✊🏽",	//fist_raised_medium_skin_tone
	"✊🏾",	//fist_medium_dark_skin_tone
	"✊🏾",	//fist_raised_medium_dark_skin_tone
	"✊🏿",	//fist_dark_skin_tone
	"✊🏿",	//fist_raised_dark_skin_tone
	"✋🏻",	//hand_light_skin_tone
	"✋🏻",	//raised_hand_light_skin_tone
	"✋🏼",	//hand_medium_light_skin_tone
	"✋🏼",	//raised_hand_medium_light_skin_tone
	"✋🏽",	//hand_medium_skin_tone
	"✋🏽",	//raised_hand_medium_skin_tone
	"✋🏾",	//hand_medium_dark_skin_tone
	"✋🏾",	//raised_hand_medium_dark_skin_tone
	"✋🏿",	//hand_dark_skin_tone
	"✋🏿",	//raised_hand_dark_skin_tone
	"✌🏻",	//v_light_skin_tone
	"✌🏼",	//v_medium_light_skin_tone
	"✌🏽",	//v_medium_skin_tone
	"✌🏾",	//v_medium_dark_skin_tone
	"✌🏿",	//v_dark_skin_tone
	"✍🏻",	//writing_hand_light_skin_tone
	"✍🏼",	//writing_hand_medium_light_skin_tone
	"✍🏽",	//writing_hand_medium_skin_tone
	"✍🏾",	//writing_hand_medium_dark_skin_tone
	"✍🏿",	//writing_hand_dark_skin_tone
	"",		//mattermost
};

static const QMap<QString, uint32_t> emojiMap {
	{"",0},
	{"grinning",1},
	{"smiley",2},
	{"smile",3},
	{"grin",4},
	{"laughing",5},
	{"satisfied",6},
	{"sweat_smile",7},
	{"rolling_on_the_floor_laughing",8},
	{"rofl",9},
	{"joy",10},
	{"slightly_smiling_face",11},
	{"upside_down_face",12},
	{"wink",13},
	{"blush",14},
	{"innocent",15},
	{"smiling_face_with_3_hearts",16},
	{"heart_eyes",17},
	{"star-struck",18},
	{"grinning_face_with_star_eyes",19},
	{"kissing_heart",20},
	{"kissing",21},
	{"relaxed",22},
	{"kissing_closed_eyes",23},
	{"kissing_smiling_eyes",24},
	{"smiling_face_with_tear",25},
	{"yum",26},
	{"stuck_out_tongue",27},
	{"stuck_out_tongue_winking_eye",28},
	{"zany_face",29},
	{"grinning_face_with_one_large_and_one_small_eye",30},
	{"stuck_out_tongue_closed_eyes",31},
	{"money_mouth_face",32},
	{"hugging_face",33},
	{"hugs",34},
	{"face_with_hand_over_mouth",35},
	{"smiling_face_with_smiling_eyes_and_hand_covering_mouth",36},
	{"shushing_face",37},
	{"face_with_finger_covering_closed_lips",38},
	{"thinking_face",39},
	{"thinking",40},
	{"zipper_mouth_face",41},
	{"face_with_raised_eyebrow",42},
	{"face_with_one_eyebrow_raised",43},
	{"neutral_face",44},
	{"expressionless",45},
	{"no_mouth",46},
	{"smirk",47},
	{"unamused",48},
	{"face_with_rolling_eyes",49},
	{"roll_eyes",50},
	{"grimacing",51},
	{"lying_face",52},
	{"relieved",53},
	{"pensive",54},
	{"sleepy",55},
	{"drooling_face",56},
	{"sleeping",57},
	{"mask",58},
	{"face_with_thermometer",59},
	{"face_with_head_bandage",60},
	{"nauseated_face",61},
	{"face_vomiting",62},
	{"face_with_open_mouth_vomiting",63},
	{"sneezing_face",64},
	{"hot_face",65},
	{"cold_face",66},
	{"woozy_face",67},
	{"dizzy_face",68},
	{"exploding_head",69},
	{"shocked_face_with_exploding_head",70},
	{"face_with_cowboy_hat",71},
	{"cowboy_hat_face",72},
	{"partying_face",73},
	{"disguised_face",74},
	{"sunglasses",75},
	{"nerd_face",76},
	{"face_with_monocle",77},
	{"confused",78},
	{"worried",79},
	{"slightly_frowning_face",80},
	{"white_frowning_face",81},
	{"frowning_face",82},
	{"open_mouth",83},
	{"hushed",84},
	{"astonished",85},
	{"flushed",86},
	{"pleading_face",87},
	{"frowning",88},
	{"anguished",89},
	{"fearful",90},
	{"cold_sweat",91},
	{"disappointed_relieved",92},
	{"cry",93},
	{"sob",94},
	{"scream",95},
	{"confounded",96},
	{"persevere",97},
	{"disappointed",98},
	{"sweat",99},
	{"weary",100},
	{"tired_face",101},
	{"yawning_face",102},
	{"triumph",103},
	{"rage",104},
	{"pout",105},
	{"angry",106},
	{"face_with_symbols_on_mouth",107},
	{"serious_face_with_symbols_covering_mouth",108},
	{"smiling_imp",109},
	{"imp",110},
	{"skull",111},
	{"skull_and_crossbones",112},
	{"hankey",113},
	{"poop",114},
	{"shit",115},
	{"clown_face",116},
	{"japanese_ogre",117},
	{"japanese_goblin",118},
	{"ghost",119},
	{"alien",120},
	{"space_invader",121},
	{"robot_face",122},
	{"robot",123},
	{"smiley_cat",124},
	{"smile_cat",125},
	{"joy_cat",126},
	{"heart_eyes_cat",127},
	{"smirk_cat",128},
	{"kissing_cat",129},
	{"scream_cat",130},
	{"crying_cat_face",131},
	{"pouting_cat",132},
	{"see_no_evil",133},
	{"hear_no_evil",134},
	{"speak_no_evil",135},
	{"kiss",136},
	{"love_letter",137},
	{"cupid",138},
	{"gift_heart",139},
	{"sparkling_heart",140},
	{"heartpulse",141},
	{"heartbeat",142},
	{"revolving_hearts",143},
	{"two_hearts",144},
	{"heart_decoration",145},
	{"heavy_heart_exclamation_mark_ornament",146},
	{"heavy_heart_exclamation",147},
	{"broken_heart",148},
	{"heart",149},
	{"orange_heart",150},
	{"yellow_heart",151},
	{"green_heart",152},
	{"blue_heart",153},
	{"purple_heart",154},
	{"brown_heart",155},
	{"black_heart",156},
	{"white_heart",157},
	{"100",158},
	{"anger",159},
	{"boom",160},
	{"collision",161},
	{"dizzy",162},
	{"sweat_drops",163},
	{"dash",164},
	{"hole",165},
	{"bomb",166},
	{"speech_balloon",167},
	{"eye-in-speech-bubble",168},
	{"left_speech_bubble",169},
	{"right_anger_bubble",170},
	{"thought_balloon",171},
	{"zzz",172},
	{"wave",173},
	{"raised_back_of_hand",174},
	{"raised_hand_with_fingers_splayed",175},
	{"hand",176},
	{"raised_hand",177},
	{"spock-hand",178},
	{"vulcan_salute",179},
	{"ok_hand",180},
	{"pinched_fingers",181},
	{"pinching_hand",182},
	{"v",183},
	{"crossed_fingers",184},
	{"hand_with_index_and_middle_fingers_crossed",185},
	{"i_love_you_hand_sign",186},
	{"the_horns",187},
	{"sign_of_the_horns",188},
	{"metal",189},
	{"call_me_hand",190},
	{"point_left",191},
	{"point_right",192},
	{"point_up_2",193},
	{"middle_finger",194},
	{"reversed_hand_with_middle_finger_extended",195},
	{"fu",196},
	{"point_down",197},
	{"point_up",198},
	{"+1",199},
	{"thumbsup",200},
	{"-1",201},
	{"thumbsdown",202},
	{"fist",203},
	{"fist_raised",204},
	{"facepunch",205},
	{"punch",206},
	{"fist_oncoming",207},
	{"left-facing_fist",208},
	{"fist_left",209},
	{"right-facing_fist",210},
	{"fist_right",211},
	{"clap",212},
	{"raised_hands",213},
	{"open_hands",214},
	{"palms_up_together",215},
	{"handshake",216},
	{"pray",217},
	{"writing_hand",218},
	{"nail_care",219},
	{"selfie",220},
	{"muscle",221},
	{"mechanical_arm",222},
	{"mechanical_leg",223},
	{"leg",224},
	{"foot",225},
	{"ear",226},
	{"ear_with_hearing_aid",227},
	{"nose",228},
	{"brain",229},
	{"anatomical_heart",230},
	{"lungs",231},
	{"tooth",232},
	{"bone",233},
	{"eyes",234},
	{"eye",235},
	{"tongue",236},
	{"lips",237},
	{"baby",238},
	{"child",239},
	{"boy",240},
	{"girl",241},
	{"adult",242},
	{"person_with_blond_hair",243},
	{"man",244},
	{"bearded_person",245},
	{"red_haired_man",246},
	{"curly_haired_man",247},
	{"white_haired_man",248},
	{"bald_man",249},
	{"woman",250},
	{"red_haired_woman",251},
	{"red_haired_person",252},
	{"curly_haired_woman",253},
	{"curly_haired_person",254},
	{"white_haired_woman",255},
	{"white_haired_person",256},
	{"bald_woman",257},
	{"bald_person",258},
	{"blond-haired-woman",259},
	{"blonde_woman",260},
	{"blond-haired-man",261},
	{"blonde_man",262},
	{"older_adult",263},
	{"older_man",264},
	{"older_woman",265},
	{"person_frowning",266},
	{"man-frowning",267},
	{"frowning_man",268},
	{"woman-frowning",269},
	{"frowning_woman",270},
	{"person_with_pouting_face",271},
	{"man-pouting",272},
	{"pouting_man",273},
	{"woman-pouting",274},
	{"pouting_woman",275},
	{"no_good",276},
	{"man-gesturing-no",277},
	{"ng_man",278},
	{"no_good_man",279},
	{"woman-gesturing-no",280},
	{"no_good_woman",281},
	{"ng_woman",282},
	{"ok_woman",283},
	{"man-gesturing-ok",284},
	{"ok_man",285},
	{"woman-gesturing-ok",286},
	{"information_desk_person",287},
	{"man-tipping-hand",288},
	{"tipping_hand_man",289},
	{"woman-tipping-hand",290},
	{"tipping_hand_woman",291},
	{"raising_hand",292},
	{"man-raising-hand",293},
	{"raising_hand_man",294},
	{"woman-raising-hand",295},
	{"raising_hand_woman",296},
	{"deaf_person",297},
	{"deaf_man",298},
	{"deaf_woman",299},
	{"bow",300},
	{"man-bowing",301},
	{"bowing_man",302},
	{"woman-bowing",303},
	{"bowing_woman",304},
	{"face_palm",305},
	{"man-facepalming",306},
	{"man_facepalming",307},
	{"woman-facepalming",308},
	{"woman_facepalming",309},
	{"shrug",310},
	{"man-shrugging",311},
	{"man_shrugging",312},
	{"woman-shrugging",313},
	{"woman_shrugging",314},
	{"health_worker",315},
	{"doctor",316},
	{"male-doctor",317},
	{"man_health_worker",318},
	{"female-doctor",319},
	{"woman_health_worker",320},
	{"student",321},
	{"male-student",322},
	{"man_student",323},
	{"female-student",324},
	{"woman_student",325},
	{"teacher",326},
	{"male-teacher",327},
	{"man_teacher",328},
	{"female-teacher",329},
	{"woman_teacher",330},
	{"judge",331},
	{"male-judge",332},
	{"man_judge",333},
	{"female-judge",334},
	{"woman_judge",335},
	{"farmer",336},
	{"male-farmer",337},
	{"man_farmer",338},
	{"female-farmer",339},
	{"woman_farmer",340},
	{"cook",341},
	{"male-cook",342},
	{"man_cook",343},
	{"female-cook",344},
	{"woman_cook",345},
	{"mechanic",346},
	{"male-mechanic",347},
	{"man_mechanic",348},
	{"female-mechanic",349},
	{"woman_mechanic",350},
	{"factory_worker",351},
	{"male-factory-worker",352},
	{"man_factory_worker",353},
	{"female-factory-worker",354},
	{"woman_factory_worker",355},
	{"office_worker",356},
	{"male-office-worker",357},
	{"man_office_worker",358},
	{"female-office-worker",359},
	{"woman_office_worker",360},
	{"scientist",361},
	{"male-scientist",362},
	{"man_scientist",363},
	{"female-scientist",364},
	{"woman_scientist",365},
	{"technologist",366},
	{"male-technologist",367},
	{"man_technologist",368},
	{"female-technologist",369},
	{"woman_technologist",370},
	{"singer",371},
	{"male-singer",372},
	{"man_singer",373},
	{"female-singer",374},
	{"woman_singer",375},
	{"artist",376},
	{"male-artist",377},
	{"man_artist",378},
	{"female-artist",379},
	{"woman_artist",380},
	{"pilot",381},
	{"male-pilot",382},
	{"man_pilot",383},
	{"female-pilot",384},
	{"woman_pilot",385},
	{"astronaut",386},
	{"male-astronaut",387},
	{"man_astronaut",388},
	{"female-astronaut",389},
	{"woman_astronaut",390},
	{"firefighter",391},
	{"male-firefighter",392},
	{"man_firefighter",393},
	{"female-firefighter",394},
	{"woman_firefighter",395},
	{"cop",396},
	{"male-police-officer",397},
	{"policeman",398},
	{"female-police-officer",399},
	{"policewoman",400},
	{"sleuth_or_spy",401},
	{"detective",402},
	{"male-detective",403},
	{"male_detective",404},
	{"female-detective",405},
	{"female_detective",406},
	{"guardsman",407},
	{"male-guard",408},
	{"female-guard",409},
	{"guardswoman",410},
	{"ninja",411},
	{"construction_worker",412},
	{"male-construction-worker",413},
	{"construction_worker_man",414},
	{"female-construction-worker",415},
	{"construction_worker_woman",416},
	{"prince",417},
	{"princess",418},
	{"man_with_turban",419},
	{"man-wearing-turban",420},
	{"woman-wearing-turban",421},
	{"woman_with_turban",422},
	{"man_with_gua_pi_mao",423},
	{"person_with_headscarf",424},
	{"person_in_tuxedo",425},
	{"man_in_tuxedo",426},
	{"woman_in_tuxedo",427},
	{"bride_with_veil",428},
	{"man_with_veil",429},
	{"woman_with_veil",430},
	{"pregnant_woman",431},
	{"breast-feeding",432},
	{"woman_feeding_baby",433},
	{"man_feeding_baby",434},
	{"person_feeding_baby",435},
	{"angel",436},
	{"santa",437},
	{"mrs_claus",438},
	{"mother_christmas",439},
	{"mx_claus",440},
	{"superhero",441},
	{"male_superhero",442},
	{"female_superhero",443},
	{"supervillain",444},
	{"male_supervillain",445},
	{"female_supervillain",446},
	{"mage",447},
	{"male_mage",448},
	{"female_mage",449},
	{"fairy",450},
	{"male_fairy",451},
	{"female_fairy",452},
	{"vampire",453},
	{"male_vampire",454},
	{"female_vampire",455},
	{"merperson",456},
	{"merman",457},
	{"mermaid",458},
	{"elf",459},
	{"male_elf",460},
	{"female_elf",461},
	{"genie",462},
	{"male_genie",463},
	{"female_genie",464},
	{"zombie",465},
	{"male_zombie",466},
	{"female_zombie",467},
	{"massage",468},
	{"man-getting-massage",469},
	{"massage_man",470},
	{"woman-getting-massage",471},
	{"massage_woman",472},
	{"haircut",473},
	{"man-getting-haircut",474},
	{"haircut_man",475},
	{"woman-getting-haircut",476},
	{"haircut_woman",477},
	{"walking",478},
	{"man-walking",479},
	{"walking_man",480},
	{"woman-walking",481},
	{"walking_woman",482},
	{"standing_person",483},
	{"man_standing",484},
	{"woman_standing",485},
	{"kneeling_person",486},
	{"man_kneeling",487},
	{"woman_kneeling",488},
	{"person_with_probing_cane",489},
	{"man_with_probing_cane",490},
	{"woman_with_probing_cane",491},
	{"person_in_motorized_wheelchair",492},
	{"man_in_motorized_wheelchair",493},
	{"woman_in_motorized_wheelchair",494},
	{"person_in_manual_wheelchair",495},
	{"man_in_manual_wheelchair",496},
	{"woman_in_manual_wheelchair",497},
	{"runner",498},
	{"running",499},
	{"man-running",500},
	{"running_man",501},
	{"woman-running",502},
	{"running_woman",503},
	{"dancer",504},
	{"man_dancing",505},
	{"man_in_business_suit_levitating",506},
	{"business_suit_levitating",507},
	{"dancers",508},
	{"man-with-bunny-ears-partying",509},
	{"dancing_men",510},
	{"woman-with-bunny-ears-partying",511},
	{"dancing_women",512},
	{"person_in_steamy_room",513},
	{"man_in_steamy_room",514},
	{"woman_in_steamy_room",515},
	{"person_climbing",516},
	{"man_climbing",517},
	{"woman_climbing",518},
	{"fencer",519},
	{"person_fencing",520},
	{"horse_racing",521},
	{"skier",522},
	{"snowboarder",523},
	{"golfer",524},
	{"man-golfing",525},
	{"golfing_man",526},
	{"woman-golfing",527},
	{"golfing_woman",528},
	{"surfer",529},
	{"man-surfing",530},
	{"surfing_man",531},
	{"woman-surfing",532},
	{"surfing_woman",533},
	{"rowboat",534},
	{"man-rowing-boat",535},
	{"rowing_man",536},
	{"woman-rowing-boat",537},
	{"rowing_woman",538},
	{"swimmer",539},
	{"man-swimming",540},
	{"swimming_man",541},
	{"woman-swimming",542},
	{"swimming_woman",543},
	{"person_with_ball",544},
	{"man-bouncing-ball",545},
	{"basketball_man",546},
	{"woman-bouncing-ball",547},
	{"basketball_woman",548},
	{"weight_lifter",549},
	{"man-lifting-weights",550},
	{"weight_lifting_man",551},
	{"woman-lifting-weights",552},
	{"weight_lifting_woman",553},
	{"bicyclist",554},
	{"man-biking",555},
	{"biking_man",556},
	{"woman-biking",557},
	{"biking_woman",558},
	{"mountain_bicyclist",559},
	{"man-mountain-biking",560},
	{"mountain_biking_man",561},
	{"woman-mountain-biking",562},
	{"mountain_biking_woman",563},
	{"person_doing_cartwheel",564},
	{"man-cartwheeling",565},
	{"man_cartwheeling",566},
	{"woman-cartwheeling",567},
	{"woman_cartwheeling",568},
	{"wrestlers",569},
	{"man-wrestling",570},
	{"men_wrestling",571},
	{"woman-wrestling",572},
	{"women_wrestling",573},
	{"water_polo",574},
	{"man-playing-water-polo",575},
	{"man_playing_water_polo",576},
	{"woman-playing-water-polo",577},
	{"woman_playing_water_polo",578},
	{"handball",579},
	{"man-playing-handball",580},
	{"man_playing_handball",581},
	{"woman-playing-handball",582},
	{"woman_playing_handball",583},
	{"juggling",584},
	{"man-juggling",585},
	{"man_juggling",586},
	{"woman-juggling",587},
	{"woman_juggling",588},
	{"person_in_lotus_position",589},
	{"man_in_lotus_position",590},
	{"woman_in_lotus_position",591},
	{"bath",592},
	{"sleeping_accommodation",593},
	{"sleeping_bed",594},
	{"people_holding_hands",595},
	{"two_women_holding_hands",596},
	{"women_holding_hands",597},
	{"man_and_woman_holding_hands",598},
	{"woman_and_man_holding_hands",599},
	{"couple",600},
	{"two_men_holding_hands",601},
	{"men_holding_hands",602},
	{"couplekiss",603},
	{"woman-kiss-man",604},
	{"couplekiss_man_woman",605},
	{"man-kiss-man",606},
	{"couplekiss_man_man",607},
	{"woman-kiss-woman",608},
	{"couplekiss_woman_woman",609},
	{"couple_with_heart",610},
	{"woman-heart-man",611},
	{"couple_with_heart_woman_man",612},
	{"man-heart-man",613},
	{"couple_with_heart_man_man",614},
	{"woman-heart-woman",615},
	{"couple_with_heart_woman_woman",616},
	{"family",617},
	{"man-woman-boy",618},
	{"family_man_woman_boy",619},
	{"man-woman-girl",620},
	{"family_man_woman_girl",621},
	{"man-woman-girl-boy",622},
	{"family_man_woman_girl_boy",623},
	{"man-woman-boy-boy",624},
	{"family_man_woman_boy_boy",625},
	{"man-woman-girl-girl",626},
	{"family_man_woman_girl_girl",627},
	{"man-man-boy",628},
	{"family_man_man_boy",629},
	{"man-man-girl",630},
	{"family_man_man_girl",631},
	{"man-man-girl-boy",632},
	{"family_man_man_girl_boy",633},
	{"man-man-boy-boy",634},
	{"family_man_man_boy_boy",635},
	{"man-man-girl-girl",636},
	{"family_man_man_girl_girl",637},
	{"woman-woman-boy",638},
	{"family_woman_woman_boy",639},
	{"woman-woman-girl",640},
	{"family_woman_woman_girl",641},
	{"woman-woman-girl-boy",642},
	{"family_woman_woman_girl_boy",643},
	{"woman-woman-boy-boy",644},
	{"family_woman_woman_boy_boy",645},
	{"woman-woman-girl-girl",646},
	{"family_woman_woman_girl_girl",647},
	{"man-boy",648},
	{"family_man_boy",649},
	{"man-boy-boy",650},
	{"family_man_boy_boy",651},
	{"man-girl",652},
	{"family_man_girl",653},
	{"man-girl-boy",654},
	{"family_man_girl_boy",655},
	{"man-girl-girl",656},
	{"family_man_girl_girl",657},
	{"woman-boy",658},
	{"family_woman_boy",659},
	{"woman-boy-boy",660},
	{"family_woman_boy_boy",661},
	{"woman-girl",662},
	{"family_woman_girl",663},
	{"woman-girl-boy",664},
	{"family_woman_girl_boy",665},
	{"woman-girl-girl",666},
	{"family_woman_girl_girl",667},
	{"speaking_head_in_silhouette",668},
	{"speaking_head",669},
	{"bust_in_silhouette",670},
	{"busts_in_silhouette",671},
	{"people_hugging",672},
	{"footprints",673},
	{"skin-tone-2",674},
	{"skin-tone-3",675},
	{"skin-tone-4",676},
	{"skin-tone-5",677},
	{"skin-tone-6",678},
	{"monkey_face",679},
	{"monkey",680},
	{"gorilla",681},
	{"orangutan",682},
	{"dog",683},
	{"dog2",684},
	{"guide_dog",685},
	{"service_dog",686},
	{"poodle",687},
	{"wolf",688},
	{"fox_face",689},
	{"raccoon",690},
	{"cat",691},
	{"cat2",692},
	{"black_cat",693},
	{"lion_face",694},
	{"lion",695},
	{"tiger",696},
	{"tiger2",697},
	{"leopard",698},
	{"horse",699},
	{"racehorse",700},
	{"unicorn_face",701},
	{"unicorn",702},
	{"zebra_face",703},
	{"deer",704},
	{"bison",705},
	{"cow",706},
	{"ox",707},
	{"water_buffalo",708},
	{"cow2",709},
	{"pig",710},
	{"pig2",711},
	{"boar",712},
	{"pig_nose",713},
	{"ram",714},
	{"sheep",715},
	{"goat",716},
	{"dromedary_camel",717},
	{"camel",718},
	{"llama",719},
	{"giraffe_face",720},
	{"elephant",721},
	{"mammoth",722},
	{"rhinoceros",723},
	{"hippopotamus",724},
	{"mouse",725},
	{"mouse2",726},
	{"rat",727},
	{"hamster",728},
	{"rabbit",729},
	{"rabbit2",730},
	{"chipmunk",731},
	{"beaver",732},
	{"hedgehog",733},
	{"bat",734},
	{"bear",735},
	{"polar_bear",736},
	{"koala",737},
	{"panda_face",738},
	{"sloth",739},
	{"otter",740},
	{"skunk",741},
	{"kangaroo",742},
	{"badger",743},
	{"feet",744},
	{"paw_prints",745},
	{"turkey",746},
	{"chicken",747},
	{"rooster",748},
	{"hatching_chick",749},
	{"baby_chick",750},
	{"hatched_chick",751},
	{"bird",752},
	{"penguin",753},
	{"dove_of_peace",754},
	{"dove",755},
	{"eagle",756},
	{"duck",757},
	{"swan",758},
	{"owl",759},
	{"dodo",760},
	{"feather",761},
	{"flamingo",762},
	{"peacock",763},
	{"parrot",764},
	{"frog",765},
	{"crocodile",766},
	{"turtle",767},
	{"lizard",768},
	{"snake",769},
	{"dragon_face",770},
	{"dragon",771},
	{"sauropod",772},
	{"t-rex",773},
	{"whale",774},
	{"whale2",775},
	{"dolphin",776},
	{"flipper",777},
	{"seal",778},
	{"fish",779},
	{"tropical_fish",780},
	{"blowfish",781},
	{"shark",782},
	{"octopus",783},
	{"shell",784},
	{"snail",785},
	{"butterfly",786},
	{"bug",787},
	{"ant",788},
	{"bee",789},
	{"honeybee",790},
	{"beetle",791},
	{"ladybug",792},
	{"lady_beetle",793},
	{"cricket",794},
	{"cockroach",795},
	{"spider",796},
	{"spider_web",797},
	{"scorpion",798},
	{"mosquito",799},
	{"fly",800},
	{"worm",801},
	{"microbe",802},
	{"bouquet",803},
	{"cherry_blossom",804},
	{"white_flower",805},
	{"rosette",806},
	{"rose",807},
	{"wilted_flower",808},
	{"hibiscus",809},
	{"sunflower",810},
	{"blossom",811},
	{"tulip",812},
	{"seedling",813},
	{"potted_plant",814},
	{"evergreen_tree",815},
	{"deciduous_tree",816},
	{"palm_tree",817},
	{"cactus",818},
	{"ear_of_rice",819},
	{"herb",820},
	{"shamrock",821},
	{"four_leaf_clover",822},
	{"maple_leaf",823},
	{"fallen_leaf",824},
	{"leaves",825},
	{"grapes",826},
	{"melon",827},
	{"watermelon",828},
	{"tangerine",829},
	{"mandarin",830},
	{"orange",831},
	{"lemon",832},
	{"banana",833},
	{"pineapple",834},
	{"mango",835},
	{"apple",836},
	{"green_apple",837},
	{"pear",838},
	{"peach",839},
	{"cherries",840},
	{"strawberry",841},
	{"blueberries",842},
	{"kiwifruit",843},
	{"kiwi_fruit",844},
	{"tomato",845},
	{"olive",846},
	{"coconut",847},
	{"avocado",848},
	{"eggplant",849},
	{"potato",850},
	{"carrot",851},
	{"corn",852},
	{"hot_pepper",853},
	{"bell_pepper",854},
	{"cucumber",855},
	{"leafy_green",856},
	{"broccoli",857},
	{"garlic",858},
	{"onion",859},
	{"mushroom",860},
	{"peanuts",861},
	{"chestnut",862},
	{"bread",863},
	{"croissant",864},
	{"baguette_bread",865},
	{"flatbread",866},
	{"pretzel",867},
	{"bagel",868},
	{"pancakes",869},
	{"waffle",870},
	{"cheese_wedge",871},
	{"cheese",872},
	{"meat_on_bone",873},
	{"poultry_leg",874},
	{"cut_of_meat",875},
	{"bacon",876},
	{"hamburger",877},
	{"fries",878},
	{"pizza",879},
	{"hotdog",880},
	{"sandwich",881},
	{"taco",882},
	{"burrito",883},
	{"tamale",884},
	{"stuffed_flatbread",885},
	{"falafel",886},
	{"egg",887},
	{"fried_egg",888},
	{"cooking",889},
	{"shallow_pan_of_food",890},
	{"stew",891},
	{"fondue",892},
	{"bowl_with_spoon",893},
	{"green_salad",894},
	{"popcorn",895},
	{"butter",896},
	{"salt",897},
	{"canned_food",898},
	{"bento",899},
	{"rice_cracker",900},
	{"rice_ball",901},
	{"rice",902},
	{"curry",903},
	{"ramen",904},
	{"spaghetti",905},
	{"sweet_potato",906},
	{"oden",907},
	{"sushi",908},
	{"fried_shrimp",909},
	{"fish_cake",910},
	{"moon_cake",911},
	{"dango",912},
	{"dumpling",913},
	{"fortune_cookie",914},
	{"takeout_box",915},
	{"crab",916},
	{"lobster",917},
	{"shrimp",918},
	{"squid",919},
	{"oyster",920},
	{"icecream",921},
	{"shaved_ice",922},
	{"ice_cream",923},
	{"doughnut",924},
	{"cookie",925},
	{"birthday",926},
	{"cake",927},
	{"cupcake",928},
	{"pie",929},
	{"chocolate_bar",930},
	{"candy",931},
	{"lollipop",932},
	{"custard",933},
	{"honey_pot",934},
	{"baby_bottle",935},
	{"glass_of_milk",936},
	{"milk_glass",937},
	{"coffee",938},
	{"teapot",939},
	{"tea",940},
	{"sake",941},
	{"champagne",942},
	{"wine_glass",943},
	{"cocktail",944},
	{"tropical_drink",945},
	{"beer",946},
	{"beers",947},
	{"clinking_glasses",948},
	{"tumbler_glass",949},
	{"cup_with_straw",950},
	{"bubble_tea",951},
	{"beverage_box",952},
	{"mate_drink",953},
	{"ice_cube",954},
	{"chopsticks",955},
	{"knife_fork_plate",956},
	{"plate_with_cutlery",957},
	{"fork_and_knife",958},
	{"spoon",959},
	{"hocho",960},
	{"knife",961},
	{"amphora",962},
	{"earth_africa",963},
	{"earth_americas",964},
	{"earth_asia",965},
	{"globe_with_meridians",966},
	{"world_map",967},
	{"japan",968},
	{"compass",969},
	{"snow_capped_mountain",970},
	{"mountain_snow",971},
	{"mountain",972},
	{"volcano",973},
	{"mount_fuji",974},
	{"camping",975},
	{"beach_with_umbrella",976},
	{"beach_umbrella",977},
	{"desert",978},
	{"desert_island",979},
	{"national_park",980},
	{"stadium",981},
	{"classical_building",982},
	{"building_construction",983},
	{"bricks",984},
	{"rock",985},
	{"wood",986},
	{"hut",987},
	{"house_buildings",988},
	{"houses",989},
	{"derelict_house_building",990},
	{"derelict_house",991},
	{"house",992},
	{"house_with_garden",993},
	{"office",994},
	{"post_office",995},
	{"european_post_office",996},
	{"hospital",997},
	{"bank",998},
	{"hotel",999},
	{"love_hotel",1000},
	{"convenience_store",1001},
	{"school",1002},
	{"department_store",1003},
	{"factory",1004},
	{"japanese_castle",1005},
	{"european_castle",1006},
	{"wedding",1007},
	{"tokyo_tower",1008},
	{"statue_of_liberty",1009},
	{"church",1010},
	{"mosque",1011},
	{"hindu_temple",1012},
	{"synagogue",1013},
	{"shinto_shrine",1014},
	{"kaaba",1015},
	{"fountain",1016},
	{"tent",1017},
	{"foggy",1018},
	{"night_with_stars",1019},
	{"cityscape",1020},
	{"sunrise_over_mountains",1021},
	{"sunrise",1022},
	{"city_sunset",1023},
	{"city_sunrise",1024},
	{"bridge_at_night",1025},
	{"hotsprings",1026},
	{"carousel_horse",1027},
	{"ferris_wheel",1028},
	{"roller_coaster",1029},
	{"barber",1030},
	{"circus_tent",1031},
	{"steam_locomotive",1032},
	{"railway_car",1033},
	{"bullettrain_side",1034},
	{"bullettrain_front",1035},
	{"train2",1036},
	{"metro",1037},
	{"light_rail",1038},
	{"station",1039},
	{"tram",1040},
	{"monorail",1041},
	{"mountain_railway",1042},
	{"train",1043},
	{"bus",1044},
	{"oncoming_bus",1045},
	{"trolleybus",1046},
	{"minibus",1047},
	{"ambulance",1048},
	{"fire_engine",1049},
	{"police_car",1050},
	{"oncoming_police_car",1051},
	{"taxi",1052},
	{"oncoming_taxi",1053},
	{"car",1054},
	{"red_car",1055},
	{"oncoming_automobile",1056},
	{"blue_car",1057},
	{"pickup_truck",1058},
	{"truck",1059},
	{"articulated_lorry",1060},
	{"tractor",1061},
	{"racing_car",1062},
	{"racing_motorcycle",1063},
	{"motorcycle",1064},
	{"motor_scooter",1065},
	{"manual_wheelchair",1066},
	{"motorized_wheelchair",1067},
	{"auto_rickshaw",1068},
	{"bike",1069},
	{"scooter",1070},
	{"kick_scooter",1071},
	{"skateboard",1072},
	{"roller_skate",1073},
	{"busstop",1074},
	{"motorway",1075},
	{"railway_track",1076},
	{"oil_drum",1077},
	{"fuelpump",1078},
	{"rotating_light",1079},
	{"traffic_light",1080},
	{"vertical_traffic_light",1081},
	{"octagonal_sign",1082},
	{"stop_sign",1083},
	{"construction",1084},
	{"anchor",1085},
	{"boat",1086},
	{"sailboat",1087},
	{"canoe",1088},
	{"speedboat",1089},
	{"passenger_ship",1090},
	{"ferry",1091},
	{"motor_boat",1092},
	{"ship",1093},
	{"airplane",1094},
	{"small_airplane",1095},
	{"airplane_departure",1096},
	{"flight_departure",1097},
	{"airplane_arriving",1098},
	{"flight_arrival",1099},
	{"parachute",1100},
	{"seat",1101},
	{"helicopter",1102},
	{"suspension_railway",1103},
	{"mountain_cableway",1104},
	{"aerial_tramway",1105},
	{"satellite",1106},
	{"artificial_satellite",1107},
	{"rocket",1108},
	{"flying_saucer",1109},
	{"bellhop_bell",1110},
	{"luggage",1111},
	{"hourglass",1112},
	{"hourglass_flowing_sand",1113},
	{"watch",1114},
	{"alarm_clock",1115},
	{"stopwatch",1116},
	{"timer_clock",1117},
	{"mantelpiece_clock",1118},
	{"clock12",1119},
	{"clock1230",1120},
	{"clock1",1121},
	{"clock130",1122},
	{"clock2",1123},
	{"clock230",1124},
	{"clock3",1125},
	{"clock330",1126},
	{"clock4",1127},
	{"clock430",1128},
	{"clock5",1129},
	{"clock530",1130},
	{"clock6",1131},
	{"clock630",1132},
	{"clock7",1133},
	{"clock730",1134},
	{"clock8",1135},
	{"clock830",1136},
	{"clock9",1137},
	{"clock930",1138},
	{"clock10",1139},
	{"clock1030",1140},
	{"clock11",1141},
	{"clock1130",1142},
	{"new_moon",1143},
	{"waxing_crescent_moon",1144},
	{"first_quarter_moon",1145},
	{"moon",1146},
	{"waxing_gibbous_moon",1147},
	{"full_moon",1148},
	{"waning_gibbous_moon",1149},
	{"last_quarter_moon",1150},
	{"waning_crescent_moon",1151},
	{"crescent_moon",1152},
	{"new_moon_with_face",1153},
	{"first_quarter_moon_with_face",1154},
	{"last_quarter_moon_with_face",1155},
	{"thermometer",1156},
	{"sunny",1157},
	{"full_moon_with_face",1158},
	{"sun_with_face",1159},
	{"ringed_planet",1160},
	{"star",1161},
	{"star2",1162},
	{"stars",1163},
	{"milky_way",1164},
	{"cloud",1165},
	{"partly_sunny",1166},
	{"thunder_cloud_and_rain",1167},
	{"cloud_with_lightning_and_rain",1168},
	{"mostly_sunny",1169},
	{"sun_small_cloud",1170},
	{"sun_behind_small_cloud",1171},
	{"barely_sunny",1172},
	{"sun_behind_cloud",1173},
	{"sun_behind_large_cloud",1174},
	{"partly_sunny_rain",1175},
	{"sun_behind_rain_cloud",1176},
	{"rain_cloud",1177},
	{"cloud_with_rain",1178},
	{"snow_cloud",1179},
	{"cloud_with_snow",1180},
	{"lightning",1181},
	{"lightning_cloud",1182},
	{"cloud_with_lightning",1183},
	{"tornado",1184},
	{"tornado_cloud",1185},
	{"fog",1186},
	{"wind_blowing_face",1187},
	{"wind_face",1188},
	{"cyclone",1189},
	{"rainbow",1190},
	{"closed_umbrella",1191},
	{"umbrella",1192},
	{"open_umbrella",1193},
	{"umbrella_with_rain_drops",1194},
	{"umbrella_on_ground",1195},
	{"parasol_on_ground",1196},
	{"zap",1197},
	{"snowflake",1198},
	{"snowman",1199},
	{"snowman_with_snow",1200},
	{"snowman_without_snow",1201},
	{"comet",1202},
	{"fire",1203},
	{"droplet",1204},
	{"ocean",1205},
	{"jack_o_lantern",1206},
	{"christmas_tree",1207},
	{"fireworks",1208},
	{"sparkler",1209},
	{"firecracker",1210},
	{"sparkles",1211},
	{"balloon",1212},
	{"tada",1213},
	{"confetti_ball",1214},
	{"tanabata_tree",1215},
	{"bamboo",1216},
	{"dolls",1217},
	{"flags",1218},
	{"wind_chime",1219},
	{"rice_scene",1220},
	{"red_envelope",1221},
	{"ribbon",1222},
	{"gift",1223},
	{"reminder_ribbon",1224},
	{"admission_tickets",1225},
	{"tickets",1226},
	{"ticket",1227},
	{"medal",1228},
	{"medal_military",1229},
	{"trophy",1230},
	{"sports_medal",1231},
	{"medal_sports",1232},
	{"first_place_medal",1233},
	{"1st_place_medal",1234},
	{"second_place_medal",1235},
	{"2nd_place_medal",1236},
	{"third_place_medal",1237},
	{"3rd_place_medal",1238},
	{"soccer",1239},
	{"baseball",1240},
	{"softball",1241},
	{"basketball",1242},
	{"volleyball",1243},
	{"football",1244},
	{"rugby_football",1245},
	{"tennis",1246},
	{"flying_disc",1247},
	{"bowling",1248},
	{"cricket_bat_and_ball",1249},
	{"field_hockey_stick_and_ball",1250},
	{"field_hockey",1251},
	{"ice_hockey_stick_and_puck",1252},
	{"ice_hockey",1253},
	{"lacrosse",1254},
	{"table_tennis_paddle_and_ball",1255},
	{"ping_pong",1256},
	{"badminton_racquet_and_shuttlecock",1257},
	{"badminton",1258},
	{"boxing_glove",1259},
	{"martial_arts_uniform",1260},
	{"goal_net",1261},
	{"golf",1262},
	{"ice_skate",1263},
	{"fishing_pole_and_fish",1264},
	{"diving_mask",1265},
	{"running_shirt_with_sash",1266},
	{"ski",1267},
	{"sled",1268},
	{"curling_stone",1269},
	{"dart",1270},
	{"yo-yo",1271},
	{"kite",1272},
	{"8ball",1273},
	{"crystal_ball",1274},
	{"magic_wand",1275},
	{"nazar_amulet",1276},
	{"video_game",1277},
	{"joystick",1278},
	{"slot_machine",1279},
	{"game_die",1280},
	{"jigsaw",1281},
	{"teddy_bear",1282},
	{"pinata",1283},
	{"nesting_dolls",1284},
	{"spades",1285},
	{"hearts",1286},
	{"diamonds",1287},
	{"clubs",1288},
	{"chess_pawn",1289},
	{"black_joker",1290},
	{"mahjong",1291},
	{"flower_playing_cards",1292},
	{"performing_arts",1293},
	{"frame_with_picture",1294},
	{"framed_picture",1295},
	{"art",1296},
	{"thread",1297},
	{"sewing_needle",1298},
	{"yarn",1299},
	{"knot",1300},
	{"eyeglasses",1301},
	{"dark_sunglasses",1302},
	{"goggles",1303},
	{"lab_coat",1304},
	{"safety_vest",1305},
	{"necktie",1306},
	{"shirt",1307},
	{"tshirt",1308},
	{"jeans",1309},
	{"scarf",1310},
	{"gloves",1311},
	{"coat",1312},
	{"socks",1313},
	{"dress",1314},
	{"kimono",1315},
	{"sari",1316},
	{"one-piece_swimsuit",1317},
	{"briefs",1318},
	{"shorts",1319},
	{"bikini",1320},
	{"womans_clothes",1321},
	{"purse",1322},
	{"handbag",1323},
	{"pouch",1324},
	{"shopping_bags",1325},
	{"shopping",1326},
	{"school_satchel",1327},
	{"thong_sandal",1328},
	{"mans_shoe",1329},
	{"shoe",1330},
	{"athletic_shoe",1331},
	{"hiking_boot",1332},
	{"womans_flat_shoe",1333},
	{"high_heel",1334},
	{"sandal",1335},
	{"ballet_shoes",1336},
	{"boot",1337},
	{"crown",1338},
	{"womans_hat",1339},
	{"tophat",1340},
	{"mortar_board",1341},
	{"billed_cap",1342},
	{"military_helmet",1343},
	{"helmet_with_white_cross",1344},
	{"rescue_worker_helmet",1345},
	{"prayer_beads",1346},
	{"lipstick",1347},
	{"ring",1348},
	{"gem",1349},
	{"mute",1350},
	{"speaker",1351},
	{"sound",1352},
	{"loud_sound",1353},
	{"loudspeaker",1354},
	{"mega",1355},
	{"postal_horn",1356},
	{"bell",1357},
	{"no_bell",1358},
	{"musical_score",1359},
	{"musical_note",1360},
	{"notes",1361},
	{"studio_microphone",1362},
	{"level_slider",1363},
	{"control_knobs",1364},
	{"microphone",1365},
	{"headphones",1366},
	{"radio",1367},
	{"saxophone",1368},
	{"accordion",1369},
	{"guitar",1370},
	{"musical_keyboard",1371},
	{"trumpet",1372},
	{"violin",1373},
	{"banjo",1374},
	{"drum_with_drumsticks",1375},
	{"drum",1376},
	{"long_drum",1377},
	{"iphone",1378},
	{"calling",1379},
	{"phone",1380},
	{"telephone",1381},
	{"telephone_receiver",1382},
	{"pager",1383},
	{"fax",1384},
	{"battery",1385},
	{"electric_plug",1386},
	{"computer",1387},
	{"desktop_computer",1388},
	{"printer",1389},
	{"keyboard",1390},
	{"three_button_mouse",1391},
	{"computer_mouse",1392},
	{"trackball",1393},
	{"minidisc",1394},
	{"floppy_disk",1395},
	{"cd",1396},
	{"dvd",1397},
	{"abacus",1398},
	{"movie_camera",1399},
	{"film_frames",1400},
	{"film_strip",1401},
	{"film_projector",1402},
	{"clapper",1403},
	{"tv",1404},
	{"camera",1405},
	{"camera_with_flash",1406},
	{"camera_flash",1407},
	{"video_camera",1408},
	{"vhs",1409},
	{"mag",1410},
	{"mag_right",1411},
	{"candle",1412},
	{"bulb",1413},
	{"flashlight",1414},
	{"izakaya_lantern",1415},
	{"lantern",1416},
	{"diya_lamp",1417},
	{"notebook_with_decorative_cover",1418},
	{"closed_book",1419},
	{"book",1420},
	{"open_book",1421},
	{"green_book",1422},
	{"blue_book",1423},
	{"orange_book",1424},
	{"books",1425},
	{"notebook",1426},
	{"ledger",1427},
	{"page_with_curl",1428},
	{"scroll",1429},
	{"page_facing_up",1430},
	{"newspaper",1431},
	{"rolled_up_newspaper",1432},
	{"newspaper_roll",1433},
	{"bookmark_tabs",1434},
	{"bookmark",1435},
	{"label",1436},
	{"moneybag",1437},
	{"coin",1438},
	{"yen",1439},
	{"dollar",1440},
	{"euro",1441},
	{"pound",1442},
	{"money_with_wings",1443},
	{"credit_card",1444},
	{"receipt",1445},
	{"chart",1446},
	{"email",1447},
	{"envelope",1448},
	{"e-mail",1449},
	{"incoming_envelope",1450},
	{"envelope_with_arrow",1451},
	{"outbox_tray",1452},
	{"inbox_tray",1453},
	{"package",1454},
	{"mailbox",1455},
	{"mailbox_closed",1456},
	{"mailbox_with_mail",1457},
	{"mailbox_with_no_mail",1458},
	{"postbox",1459},
	{"ballot_box_with_ballot",1460},
	{"ballot_box",1461},
	{"pencil2",1462},
	{"black_nib",1463},
	{"lower_left_fountain_pen",1464},
	{"fountain_pen",1465},
	{"lower_left_ballpoint_pen",1466},
	{"pen",1467},
	{"lower_left_paintbrush",1468},
	{"paintbrush",1469},
	{"lower_left_crayon",1470},
	{"crayon",1471},
	{"memo",1472},
	{"pencil",1473},
	{"briefcase",1474},
	{"file_folder",1475},
	{"open_file_folder",1476},
	{"card_index_dividers",1477},
	{"date",1478},
	{"calendar",1479},
	{"spiral_note_pad",1480},
	{"spiral_notepad",1481},
	{"spiral_calendar_pad",1482},
	{"spiral_calendar",1483},
	{"card_index",1484},
	{"chart_with_upwards_trend",1485},
	{"chart_with_downwards_trend",1486},
	{"bar_chart",1487},
	{"clipboard",1488},
	{"pushpin",1489},
	{"round_pushpin",1490},
	{"paperclip",1491},
	{"linked_paperclips",1492},
	{"paperclips",1493},
	{"straight_ruler",1494},
	{"triangular_ruler",1495},
	{"scissors",1496},
	{"card_file_box",1497},
	{"file_cabinet",1498},
	{"wastebasket",1499},
	{"lock",1500},
	{"unlock",1501},
	{"lock_with_ink_pen",1502},
	{"closed_lock_with_key",1503},
	{"key",1504},
	{"old_key",1505},
	{"hammer",1506},
	{"axe",1507},
	{"pick",1508},
	{"hammer_and_pick",1509},
	{"hammer_and_wrench",1510},
	{"dagger_knife",1511},
	{"dagger",1512},
	{"crossed_swords",1513},
	{"gun",1514},
	{"boomerang",1515},
	{"bow_and_arrow",1516},
	{"shield",1517},
	{"carpentry_saw",1518},
	{"wrench",1519},
	{"screwdriver",1520},
	{"nut_and_bolt",1521},
	{"gear",1522},
	{"compression",1523},
	{"clamp",1524},
	{"scales",1525},
	{"balance_scale",1526},
	{"probing_cane",1527},
	{"link",1528},
	{"chains",1529},
	{"hook",1530},
	{"toolbox",1531},
	{"magnet",1532},
	{"ladder",1533},
	{"alembic",1534},
	{"test_tube",1535},
	{"petri_dish",1536},
	{"dna",1537},
	{"microscope",1538},
	{"telescope",1539},
	{"satellite_antenna",1540},
	{"syringe",1541},
	{"drop_of_blood",1542},
	{"pill",1543},
	{"adhesive_bandage",1544},
	{"stethoscope",1545},
	{"door",1546},
	{"elevator",1547},
	{"mirror",1548},
	{"window",1549},
	{"bed",1550},
	{"couch_and_lamp",1551},
	{"chair",1552},
	{"toilet",1553},
	{"plunger",1554},
	{"shower",1555},
	{"bathtub",1556},
	{"mouse_trap",1557},
	{"razor",1558},
	{"lotion_bottle",1559},
	{"safety_pin",1560},
	{"broom",1561},
	{"basket",1562},
	{"roll_of_paper",1563},
	{"bucket",1564},
	{"soap",1565},
	{"toothbrush",1566},
	{"sponge",1567},
	{"fire_extinguisher",1568},
	{"shopping_trolley",1569},
	{"shopping_cart",1570},
	{"smoking",1571},
	{"coffin",1572},
	{"headstone",1573},
	{"funeral_urn",1574},
	{"moyai",1575},
	{"placard",1576},
	{"atm",1577},
	{"put_litter_in_its_place",1578},
	{"potable_water",1579},
	{"wheelchair",1580},
	{"mens",1581},
	{"womens",1582},
	{"restroom",1583},
	{"baby_symbol",1584},
	{"wc",1585},
	{"passport_control",1586},
	{"customs",1587},
	{"baggage_claim",1588},
	{"left_luggage",1589},
	{"warning",1590},
	{"children_crossing",1591},
	{"no_entry",1592},
	{"no_entry_sign",1593},
	{"no_bicycles",1594},
	{"no_smoking",1595},
	{"do_not_litter",1596},
	{"non-potable_water",1597},
	{"no_pedestrians",1598},
	{"no_mobile_phones",1599},
	{"underage",1600},
	{"radioactive_sign",1601},
	{"radioactive",1602},
	{"biohazard_sign",1603},
	{"biohazard",1604},
	{"arrow_up",1605},
	{"arrow_upper_right",1606},
	{"arrow_right",1607},
	{"arrow_lower_right",1608},
	{"arrow_down",1609},
	{"arrow_lower_left",1610},
	{"arrow_left",1611},
	{"arrow_upper_left",1612},
	{"arrow_up_down",1613},
	{"left_right_arrow",1614},
	{"leftwards_arrow_with_hook",1615},
	{"arrow_right_hook",1616},
	{"arrow_heading_up",1617},
	{"arrow_heading_down",1618},
	{"arrows_clockwise",1619},
	{"arrows_counterclockwise",1620},
	{"back",1621},
	{"end",1622},
	{"on",1623},
	{"soon",1624},
	{"top",1625},
	{"place_of_worship",1626},
	{"atom_symbol",1627},
	{"om_symbol",1628},
	{"om",1629},
	{"star_of_david",1630},
	{"wheel_of_dharma",1631},
	{"yin_yang",1632},
	{"latin_cross",1633},
	{"orthodox_cross",1634},
	{"star_and_crescent",1635},
	{"peace_symbol",1636},
	{"menorah_with_nine_branches",1637},
	{"menorah",1638},
	{"six_pointed_star",1639},
	{"aries",1640},
	{"taurus",1641},
	{"gemini",1642},
	{"cancer",1643},
	{"leo",1644},
	{"virgo",1645},
	{"libra",1646},
	{"scorpius",1647},
	{"sagittarius",1648},
	{"capricorn",1649},
	{"aquarius",1650},
	{"pisces",1651},
	{"ophiuchus",1652},
	{"twisted_rightwards_arrows",1653},
	{"repeat",1654},
	{"repeat_one",1655},
	{"arrow_forward",1656},
	{"fast_forward",1657},
	{"black_right_pointing_double_triangle_with_vertical_bar",1658},
	{"next_track_button",1659},
	{"black_right_pointing_triangle_with_double_vertical_bar",1660},
	{"play_or_pause_button",1661},
	{"arrow_backward",1662},
	{"rewind",1663},
	{"black_left_pointing_double_triangle_with_vertical_bar",1664},
	{"previous_track_button",1665},
	{"arrow_up_small",1666},
	{"arrow_double_up",1667},
	{"arrow_down_small",1668},
	{"arrow_double_down",1669},
	{"double_vertical_bar",1670},
	{"pause_button",1671},
	{"black_square_for_stop",1672},
	{"stop_button",1673},
	{"black_circle_for_record",1674},
	{"record_button",1675},
	{"eject",1676},
	{"cinema",1677},
	{"low_brightness",1678},
	{"high_brightness",1679},
	{"signal_strength",1680},
	{"vibration_mode",1681},
	{"mobile_phone_off",1682},
	{"female_sign",1683},
	{"male_sign",1684},
	{"transgender_symbol",1685},
	{"heavy_multiplication_x",1686},
	{"heavy_plus_sign",1687},
	{"heavy_minus_sign",1688},
	{"heavy_division_sign",1689},
	{"infinity",1690},
	{"bangbang",1691},
	{"interrobang",1692},
	{"question",1693},
	{"grey_question",1694},
	{"grey_exclamation",1695},
	{"exclamation",1696},
	{"heavy_exclamation_mark",1697},
	{"wavy_dash",1698},
	{"currency_exchange",1699},
	{"heavy_dollar_sign",1700},
	{"medical_symbol",1701},
	{"staff_of_aesculapius",1702},
	{"recycle",1703},
	{"fleur_de_lis",1704},
	{"trident",1705},
	{"name_badge",1706},
	{"beginner",1707},
	{"o",1708},
	{"white_check_mark",1709},
	{"ballot_box_with_check",1710},
	{"heavy_check_mark",1711},
	{"x",1712},
	{"negative_squared_cross_mark",1713},
	{"curly_loop",1714},
	{"loop",1715},
	{"part_alternation_mark",1716},
	{"eight_spoked_asterisk",1717},
	{"eight_pointed_black_star",1718},
	{"sparkle",1719},
	{"copyright",1720},
	{"registered",1721},
	{"tm",1722},
	{"hash",1723},
	{"keycap_star",1724},
	{"asterisk",1725},
	{"zero",1726},
	{"one",1727},
	{"two",1728},
	{"three",1729},
	{"four",1730},
	{"five",1731},
	{"six",1732},
	{"seven",1733},
	{"eight",1734},
	{"nine",1735},
	{"keycap_ten",1736},
	{"capital_abcd",1737},
	{"abcd",1738},
	{"1234",1739},
	{"symbols",1740},
	{"abc",1741},
	{"a",1742},
	{"ab",1743},
	{"b",1744},
	{"cl",1745},
	{"cool",1746},
	{"free",1747},
	{"information_source",1748},
	{"id",1749},
	{"m",1750},
	{"new",1751},
	{"ng",1752},
	{"o2",1753},
	{"ok",1754},
	{"parking",1755},
	{"sos",1756},
	{"up",1757},
	{"vs",1758},
	{"koko",1759},
	{"sa",1760},
	{"u6708",1761},
	{"u6709",1762},
	{"u6307",1763},
	{"ideograph_advantage",1764},
	{"u5272",1765},
	{"u7121",1766},
	{"u7981",1767},
	{"accept",1768},
	{"u7533",1769},
	{"u5408",1770},
	{"u7a7a",1771},
	{"congratulations",1772},
	{"secret",1773},
	{"u55b6",1774},
	{"u6e80",1775},
	{"red_circle",1776},
	{"large_orange_circle",1777},
	{"large_yellow_circle",1778},
	{"large_green_circle",1779},
	{"large_blue_circle",1780},
	{"large_purple_circle",1781},
	{"large_brown_circle",1782},
	{"black_circle",1783},
	{"white_circle",1784},
	{"large_red_square",1785},
	{"large_orange_square",1786},
	{"large_yellow_square",1787},
	{"large_green_square",1788},
	{"large_blue_square",1789},
	{"large_purple_square",1790},
	{"large_brown_square",1791},
	{"black_large_square",1792},
	{"white_large_square",1793},
	{"black_medium_square",1794},
	{"white_medium_square",1795},
	{"black_medium_small_square",1796},
	{"white_medium_small_square",1797},
	{"black_small_square",1798},
	{"white_small_square",1799},
	{"large_orange_diamond",1800},
	{"large_blue_diamond",1801},
	{"small_orange_diamond",1802},
	{"small_blue_diamond",1803},
	{"small_red_triangle",1804},
	{"small_red_triangle_down",1805},
	{"diamond_shape_with_a_dot_inside",1806},
	{"radio_button",1807},
	{"white_square_button",1808},
	{"black_square_button",1809},
	{"checkered_flag",1810},
	{"triangular_flag_on_post",1811},
	{"crossed_flags",1812},
	{"waving_black_flag",1813},
	{"black_flag",1814},
	{"waving_white_flag",1815},
	{"white_flag",1816},
	{"rainbow-flag",1817},
	{"rainbow_flag",1818},
	{"transgender_flag",1819},
	{"pirate_flag",1820},
	{"flag-ac",1821},
	{"flag-ad",1822},
	{"andorra",1823},
	{"flag-ae",1824},
	{"united_arab_emirates",1825},
	{"flag-af",1826},
	{"afghanistan",1827},
	{"flag-ag",1828},
	{"antigua_barbuda",1829},
	{"flag-ai",1830},
	{"anguilla",1831},
	{"flag-al",1832},
	{"albania",1833},
	{"flag-am",1834},
	{"armenia",1835},
	{"flag-ao",1836},
	{"angola",1837},
	{"flag-aq",1838},
	{"antarctica",1839},
	{"flag-ar",1840},
	{"argentina",1841},
	{"flag-as",1842},
	{"american_samoa",1843},
	{"flag-at",1844},
	{"austria",1845},
	{"flag-au",1846},
	{"australia",1847},
	{"flag-aw",1848},
	{"aruba",1849},
	{"flag-ax",1850},
	{"aland_islands",1851},
	{"flag-az",1852},
	{"azerbaijan",1853},
	{"flag-ba",1854},
	{"bosnia_herzegovina",1855},
	{"flag-bb",1856},
	{"barbados",1857},
	{"flag-bd",1858},
	{"bangladesh",1859},
	{"flag-be",1860},
	{"belgium",1861},
	{"flag-bf",1862},
	{"burkina_faso",1863},
	{"flag-bg",1864},
	{"bulgaria",1865},
	{"flag-bh",1866},
	{"bahrain",1867},
	{"flag-bi",1868},
	{"burundi",1869},
	{"flag-bj",1870},
	{"benin",1871},
	{"flag-bl",1872},
	{"st_barthelemy",1873},
	{"flag-bm",1874},
	{"bermuda",1875},
	{"flag-bn",1876},
	{"brunei",1877},
	{"flag-bo",1878},
	{"bolivia",1879},
	{"flag-bq",1880},
	{"caribbean_netherlands",1881},
	{"flag-br",1882},
	{"brazil",1883},
	{"flag-bs",1884},
	{"bahamas",1885},
	{"flag-bt",1886},
	{"bhutan",1887},
	{"flag-bv",1888},
	{"flag-bw",1889},
	{"botswana",1890},
	{"flag-by",1891},
	{"belarus",1892},
	{"flag-bz",1893},
	{"belize",1894},
	{"flag-ca",1895},
	{"ca",1896},
	{"canada",1897},
	{"flag-cc",1898},
	{"cocos_islands",1899},
	{"flag-cd",1900},
	{"congo_kinshasa",1901},
	{"flag-cf",1902},
	{"central_african_republic",1903},
	{"flag-cg",1904},
	{"congo_brazzaville",1905},
	{"flag-ch",1906},
	{"switzerland",1907},
	{"flag-ci",1908},
	{"cote_divoire",1909},
	{"flag-ck",1910},
	{"cook_islands",1911},
	{"flag-cl",1912},
	{"chile",1913},
	{"flag-cm",1914},
	{"cameroon",1915},
	{"cn",1916},
	{"flag-cn",1917},
	{"flag-co",1918},
	{"colombia",1919},
	{"flag-cp",1920},
	{"flag-cr",1921},
	{"costa_rica",1922},
	{"flag-cu",1923},
	{"cuba",1924},
	{"flag-cv",1925},
	{"cape_verde",1926},
	{"flag-cw",1927},
	{"curacao",1928},
	{"flag-cx",1929},
	{"christmas_island",1930},
	{"flag-cy",1931},
	{"cyprus",1932},
	{"flag-cz",1933},
	{"czech_republic",1934},
	{"de",1935},
	{"flag-de",1936},
	{"flag-dg",1937},
	{"flag-dj",1938},
	{"djibouti",1939},
	{"flag-dk",1940},
	{"denmark",1941},
	{"flag-dm",1942},
	{"dominica",1943},
	{"flag-do",1944},
	{"dominican_republic",1945},
	{"flag-dz",1946},
	{"algeria",1947},
	{"flag-ea",1948},
	{"flag-ec",1949},
	{"ecuador",1950},
	{"flag-ee",1951},
	{"estonia",1952},
	{"flag-eg",1953},
	{"egypt",1954},
	{"flag-eh",1955},
	{"western_sahara",1956},
	{"flag-er",1957},
	{"eritrea",1958},
	{"es",1959},
	{"flag-es",1960},
	{"flag-et",1961},
	{"ethiopia",1962},
	{"flag-eu",1963},
	{"eu",1964},
	{"european_union",1965},
	{"flag-fi",1966},
	{"finland",1967},
	{"flag-fj",1968},
	{"fiji",1969},
	{"flag-fk",1970},
	{"falkland_islands",1971},
	{"flag-fm",1972},
	{"micronesia",1973},
	{"flag-fo",1974},
	{"faroe_islands",1975},
	{"fr",1976},
	{"flag-fr",1977},
	{"flag-ga",1978},
	{"gabon",1979},
	{"gb",1980},
	{"uk",1981},
	{"flag-gb",1982},
	{"flag-gd",1983},
	{"grenada",1984},
	{"flag-ge",1985},
	{"georgia",1986},
	{"flag-gf",1987},
	{"french_guiana",1988},
	{"flag-gg",1989},
	{"guernsey",1990},
	{"flag-gh",1991},
	{"ghana",1992},
	{"flag-gi",1993},
	{"gibraltar",1994},
	{"flag-gl",1995},
	{"greenland",1996},
	{"flag-gm",1997},
	{"gambia",1998},
	{"flag-gn",1999},
	{"guinea",2000},
	{"flag-gp",2001},
	{"guadeloupe",2002},
	{"flag-gq",2003},
	{"equatorial_guinea",2004},
	{"flag-gr",2005},
	{"greece",2006},
	{"flag-gs",2007},
	{"south_georgia_south_sandwich_islands",2008},
	{"flag-gt",2009},
	{"guatemala",2010},
	{"flag-gu",2011},
	{"guam",2012},
	{"flag-gw",2013},
	{"guinea_bissau",2014},
	{"flag-gy",2015},
	{"guyana",2016},
	{"flag-hk",2017},
	{"hong_kong",2018},
	{"flag-hm",2019},
	{"flag-hn",2020},
	{"honduras",2021},
	{"flag-hr",2022},
	{"croatia",2023},
	{"flag-ht",2024},
	{"haiti",2025},
	{"flag-hu",2026},
	{"hungary",2027},
	{"flag-ic",2028},
	{"canary_islands",2029},
	{"flag-id",2030},
	{"indonesia",2031},
	{"flag-ie",2032},
	{"ireland",2033},
	{"flag-il",2034},
	{"israel",2035},
	{"flag-im",2036},
	{"isle_of_man",2037},
	{"flag-in",2038},
	{"india",2039},
	{"flag-io",2040},
	{"british_indian_ocean_territory",2041},
	{"flag-iq",2042},
	{"iraq",2043},
	{"flag-ir",2044},
	{"iran",2045},
	{"flag-is",2046},
	{"iceland",2047},
	{"it",2048},
	{"flag-it",2049},
	{"flag-je",2050},
	{"jersey",2051},
	{"flag-jm",2052},
	{"jamaica",2053},
	{"flag-jo",2054},
	{"jordan",2055},
	{"jp",2056},
	{"flag-jp",2057},
	{"flag-ke",2058},
	{"kenya",2059},
	{"flag-kg",2060},
	{"kyrgyzstan",2061},
	{"flag-kh",2062},
	{"cambodia",2063},
	{"flag-ki",2064},
	{"kiribati",2065},
	{"flag-km",2066},
	{"comoros",2067},
	{"flag-kn",2068},
	{"st_kitts_nevis",2069},
	{"flag-kp",2070},
	{"north_korea",2071},
	{"kr",2072},
	{"flag-kr",2073},
	{"flag-kw",2074},
	{"kuwait",2075},
	{"flag-ky",2076},
	{"cayman_islands",2077},
	{"flag-kz",2078},
	{"kazakhstan",2079},
	{"flag-la",2080},
	{"laos",2081},
	{"flag-lb",2082},
	{"lebanon",2083},
	{"flag-lc",2084},
	{"st_lucia",2085},
	{"flag-li",2086},
	{"liechtenstein",2087},
	{"flag-lk",2088},
	{"sri_lanka",2089},
	{"flag-lr",2090},
	{"liberia",2091},
	{"flag-ls",2092},
	{"lesotho",2093},
	{"flag-lt",2094},
	{"lithuania",2095},
	{"flag-lu",2096},
	{"luxembourg",2097},
	{"flag-lv",2098},
	{"latvia",2099},
	{"flag-ly",2100},
	{"libya",2101},
	{"flag-ma",2102},
	{"morocco",2103},
	{"flag-mc",2104},
	{"monaco",2105},
	{"flag-md",2106},
	{"moldova",2107},
	{"flag-me",2108},
	{"montenegro",2109},
	{"flag-mf",2110},
	{"flag-mg",2111},
	{"madagascar",2112},
	{"flag-mh",2113},
	{"marshall_islands",2114},
	{"flag-mk",2115},
	{"macedonia",2116},
	{"flag-ml",2117},
	{"mali",2118},
	{"flag-mm",2119},
	{"myanmar",2120},
	{"flag-mn",2121},
	{"mongolia",2122},
	{"flag-mo",2123},
	{"macau",2124},
	{"flag-mp",2125},
	{"northern_mariana_islands",2126},
	{"flag-mq",2127},
	{"martinique",2128},
	{"flag-mr",2129},
	{"mauritania",2130},
	{"flag-ms",2131},
	{"montserrat",2132},
	{"flag-mt",2133},
	{"malta",2134},
	{"flag-mu",2135},
	{"mauritius",2136},
	{"flag-mv",2137},
	{"maldives",2138},
	{"flag-mw",2139},
	{"malawi",2140},
	{"flag-mx",2141},
	{"mexico",2142},
	{"flag-my",2143},
	{"malaysia",2144},
	{"flag-mz",2145},
	{"mozambique",2146},
	{"flag-na",2147},
	{"namibia",2148},
	{"flag-nc",2149},
	{"new_caledonia",2150},
	{"flag-ne",2151},
	{"niger",2152},
	{"flag-nf",2153},
	{"norfolk_island",2154},
	{"flag-ng",2155},
	{"nigeria",2156},
	{"flag-ni",2157},
	{"nicaragua",2158},
	{"flag-nl",2159},
	{"netherlands",2160},
	{"flag-no",2161},
	{"norway",2162},
	{"flag-np",2163},
	{"nepal",2164},
	{"flag-nr",2165},
	{"nauru",2166},
	{"flag-nu",2167},
	{"niue",2168},
	{"flag-nz",2169},
	{"new_zealand",2170},
	{"flag-om",2171},
	{"oman",2172},
	{"flag-pa",2173},
	{"panama",2174},
	{"flag-pe",2175},
	{"peru",2176},
	{"flag-pf",2177},
	{"french_polynesia",2178},
	{"flag-pg",2179},
	{"papua_new_guinea",2180},
	{"flag-ph",2181},
	{"philippines",2182},
	{"flag-pk",2183},
	{"pakistan",2184},
	{"pk",2185},
	{"flag-pl",2186},
	{"poland",2187},
	{"flag-pm",2188},
	{"st_pierre_miquelon",2189},
	{"flag-pn",2190},
	{"pitcairn_islands",2191},
	{"flag-pr",2192},
	{"puerto_rico",2193},
	{"flag-ps",2194},
	{"palestinian_territories",2195},
	{"flag-pt",2196},
	{"portugal",2197},
	{"flag-pw",2198},
	{"palau",2199},
	{"flag-py",2200},
	{"paraguay",2201},
	{"flag-qa",2202},
	{"qatar",2203},
	{"flag-re",2204},
	{"reunion",2205},
	{"flag-ro",2206},
	{"romania",2207},
	{"flag-rs",2208},
	{"serbia",2209},
	{"ru",2210},
	{"flag-ru",2211},
	{"flag-rw",2212},
	{"rwanda",2213},
	{"flag-sa",2214},
	{"saudi_arabia",2215},
	{"flag-sb",2216},
	{"solomon_islands",2217},
	{"flag-sc",2218},
	{"seychelles",2219},
	{"flag-sd",2220},
	{"sudan",2221},
	{"flag-se",2222},
	{"sweden",2223},
	{"flag-sg",2224},
	{"singapore",2225},
	{"flag-sh",2226},
	{"st_helena",2227},
	{"flag-si",2228},
	{"slovenia",2229},
	{"flag-sj",2230},
	{"flag-sk",2231},
	{"slovakia",2232},
	{"flag-sl",2233},
	{"sierra_leone",2234},
	{"flag-sm",2235},
	{"san_marino",2236},
	{"flag-sn",2237},
	{"senegal",2238},
	{"flag-so",2239},
	{"somalia",2240},
	{"flag-sr",2241},
	{"suriname",2242},
	{"flag-ss",2243},
	{"south_sudan",2244},
	{"flag-st",2245},
	{"sao_tome_principe",2246},
	{"flag-sv",2247},
	{"el_salvador",2248},
	{"flag-sx",2249},
	{"sint_maarten",2250},
	{"flag-sy",2251},
	{"syria",2252},
	{"flag-sz",2253},
	{"swaziland",2254},
	{"flag-ta",2255},
	{"flag-tc",2256},
	{"turks_caicos_islands",2257},
	{"flag-td",2258},
	{"chad",2259},
	{"flag-tf",2260},
	{"french_southern_territories",2261},
	{"flag-tg",2262},
	{"togo",2263},
	{"flag-th",2264},
	{"thailand",2265},
	{"flag-tj",2266},
	{"tajikistan",2267},
	{"flag-tk",2268},
	{"tokelau",2269},
	{"flag-tl",2270},
	{"timor_leste",2271},
	{"flag-tm",2272},
	{"turkmenistan",2273},
	{"flag-tn",2274},
	{"tunisia",2275},
	{"flag-to",2276},
	{"tonga",2277},
	{"flag-tr",2278},
	{"tr",2279},
	{"flag-tt",2280},
	{"trinidad_tobago",2281},
	{"flag-tv",2282},
	{"tuvalu",2283},
	{"flag-tw",2284},
	{"taiwan",2285},
	{"flag-tz",2286},
	{"tanzania",2287},
	{"flag-ua",2288},
	{"ukraine",2289},
	{"flag-ug",2290},
	{"uganda",2291},
	{"flag-um",2292},
	{"flag-un",2293},
	{"us",2294},
	{"flag-us",2295},
	{"flag-uy",2296},
	{"uruguay",2297},
	{"flag-uz",2298},
	{"uzbekistan",2299},
	{"flag-va",2300},
	{"vatican_city",2301},
	{"flag-vc",2302},
	{"st_vincent_grenadines",2303},
	{"flag-ve",2304},
	{"venezuela",2305},
	{"flag-vg",2306},
	{"british_virgin_islands",2307},
	{"flag-vi",2308},
	{"us_virgin_islands",2309},
	{"flag-vn",2310},
	{"vietnam",2311},
	{"flag-vu",2312},
	{"vanuatu",2313},
	{"flag-wf",2314},
	{"wallis_futuna",2315},
	{"flag-ws",2316},
	{"samoa",2317},
	{"flag-xk",2318},
	{"kosovo",2319},
	{"flag-ye",2320},
	{"yemen",2321},
	{"flag-yt",2322},
	{"mayotte",2323},
	{"flag-za",2324},
	{"south_africa",2325},
	{"za",2326},
	{"flag-zm",2327},
	{"zambia",2328},
	{"flag-zw",2329},
	{"zimbabwe",2330},
	{"flag-england",2331},
	{"flag-scotland",2332},
	{"flag-wales",2333},
	{"santa_light_skin_tone",2334},
	{"santa_medium_light_skin_tone",2335},
	{"santa_medium_skin_tone",2336},
	{"santa_medium_dark_skin_tone",2337},
	{"santa_dark_skin_tone",2338},
	{"snowboarder_light_skin_tone",2339},
	{"snowboarder_medium_light_skin_tone",2340},
	{"snowboarder_medium_skin_tone",2341},
	{"snowboarder_medium_dark_skin_tone",2342},
	{"snowboarder_dark_skin_tone",2343},
	{"woman-running_light_skin_tone",2344},
	{"running_woman_light_skin_tone",2345},
	{"woman-running_medium_light_skin_tone",2346},
	{"running_woman_medium_light_skin_tone",2347},
	{"woman-running_medium_skin_tone",2348},
	{"running_woman_medium_skin_tone",2349},
	{"woman-running_medium_dark_skin_tone",2350},
	{"running_woman_medium_dark_skin_tone",2351},
	{"woman-running_dark_skin_tone",2352},
	{"running_woman_dark_skin_tone",2353},
	{"man-running_light_skin_tone",2354},
	{"running_man_light_skin_tone",2355},
	{"man-running_medium_light_skin_tone",2356},
	{"running_man_medium_light_skin_tone",2357},
	{"man-running_medium_skin_tone",2358},
	{"running_man_medium_skin_tone",2359},
	{"man-running_medium_dark_skin_tone",2360},
	{"running_man_medium_dark_skin_tone",2361},
	{"man-running_dark_skin_tone",2362},
	{"running_man_dark_skin_tone",2363},
	{"runner_light_skin_tone",2364},
	{"running_light_skin_tone",2365},
	{"runner_medium_light_skin_tone",2366},
	{"running_medium_light_skin_tone",2367},
	{"runner_medium_skin_tone",2368},
	{"running_medium_skin_tone",2369},
	{"runner_medium_dark_skin_tone",2370},
	{"running_medium_dark_skin_tone",2371},
	{"runner_dark_skin_tone",2372},
	{"running_dark_skin_tone",2373},
	{"woman-surfing_light_skin_tone",2374},
	{"surfing_woman_light_skin_tone",2375},
	{"woman-surfing_medium_light_skin_tone",2376},
	{"surfing_woman_medium_light_skin_tone",2377},
	{"woman-surfing_medium_skin_tone",2378},
	{"surfing_woman_medium_skin_tone",2379},
	{"woman-surfing_medium_dark_skin_tone",2380},
	{"surfing_woman_medium_dark_skin_tone",2381},
	{"woman-surfing_dark_skin_tone",2382},
	{"surfing_woman_dark_skin_tone",2383},
	{"man-surfing_light_skin_tone",2384},
	{"surfing_man_light_skin_tone",2385},
	{"man-surfing_medium_light_skin_tone",2386},
	{"surfing_man_medium_light_skin_tone",2387},
	{"man-surfing_medium_skin_tone",2388},
	{"surfing_man_medium_skin_tone",2389},
	{"man-surfing_medium_dark_skin_tone",2390},
	{"surfing_man_medium_dark_skin_tone",2391},
	{"man-surfing_dark_skin_tone",2392},
	{"surfing_man_dark_skin_tone",2393},
	{"surfer_light_skin_tone",2394},
	{"surfer_medium_light_skin_tone",2395},
	{"surfer_medium_skin_tone",2396},
	{"surfer_medium_dark_skin_tone",2397},
	{"surfer_dark_skin_tone",2398},
	{"horse_racing_light_skin_tone",2399},
	{"horse_racing_medium_light_skin_tone",2400},
	{"horse_racing_medium_skin_tone",2401},
	{"horse_racing_medium_dark_skin_tone",2402},
	{"horse_racing_dark_skin_tone",2403},
	{"woman-swimming_light_skin_tone",2404},
	{"swimming_woman_light_skin_tone",2405},
	{"woman-swimming_medium_light_skin_tone",2406},
	{"swimming_woman_medium_light_skin_tone",2407},
	{"woman-swimming_medium_skin_tone",2408},
	{"swimming_woman_medium_skin_tone",2409},
	{"woman-swimming_medium_dark_skin_tone",2410},
	{"swimming_woman_medium_dark_skin_tone",2411},
	{"woman-swimming_dark_skin_tone",2412},
	{"swimming_woman_dark_skin_tone",2413},
	{"man-swimming_light_skin_tone",2414},
	{"swimming_man_light_skin_tone",2415},
	{"man-swimming_medium_light_skin_tone",2416},
	{"swimming_man_medium_light_skin_tone",2417},
	{"man-swimming_medium_skin_tone",2418},
	{"swimming_man_medium_skin_tone",2419},
	{"man-swimming_medium_dark_skin_tone",2420},
	{"swimming_man_medium_dark_skin_tone",2421},
	{"man-swimming_dark_skin_tone",2422},
	{"swimming_man_dark_skin_tone",2423},
	{"swimmer_light_skin_tone",2424},
	{"swimmer_medium_light_skin_tone",2425},
	{"swimmer_medium_skin_tone",2426},
	{"swimmer_medium_dark_skin_tone",2427},
	{"swimmer_dark_skin_tone",2428},
	{"woman-lifting-weights_light_skin_tone",2429},
	{"weight_lifting_woman_light_skin_tone",2430},
	{"woman-lifting-weights_medium_light_skin_tone",2431},
	{"weight_lifting_woman_medium_light_skin_tone",2432},
	{"woman-lifting-weights_medium_skin_tone",2433},
	{"weight_lifting_woman_medium_skin_tone",2434},
	{"woman-lifting-weights_medium_dark_skin_tone",2435},
	{"weight_lifting_woman_medium_dark_skin_tone",2436},
	{"woman-lifting-weights_dark_skin_tone",2437},
	{"weight_lifting_woman_dark_skin_tone",2438},
	{"man-lifting-weights_light_skin_tone",2439},
	{"weight_lifting_man_light_skin_tone",2440},
	{"man-lifting-weights_medium_light_skin_tone",2441},
	{"weight_lifting_man_medium_light_skin_tone",2442},
	{"man-lifting-weights_medium_skin_tone",2443},
	{"weight_lifting_man_medium_skin_tone",2444},
	{"man-lifting-weights_medium_dark_skin_tone",2445},
	{"weight_lifting_man_medium_dark_skin_tone",2446},
	{"man-lifting-weights_dark_skin_tone",2447},
	{"weight_lifting_man_dark_skin_tone",2448},
	{"weight_lifter_light_skin_tone",2449},
	{"weight_lifter_medium_light_skin_tone",2450},
	{"weight_lifter_medium_skin_tone",2451},
	{"weight_lifter_medium_dark_skin_tone",2452},
	{"weight_lifter_dark_skin_tone",2453},
	{"woman-golfing_light_skin_tone",2454},
	{"golfing_woman_light_skin_tone",2455},
	{"woman-golfing_medium_light_skin_tone",2456},
	{"golfing_woman_medium_light_skin_tone",2457},
	{"woman-golfing_medium_skin_tone",2458},
	{"golfing_woman_medium_skin_tone",2459},
	{"woman-golfing_medium_dark_skin_tone",2460},
	{"golfing_woman_medium_dark_skin_tone",2461},
	{"woman-golfing_dark_skin_tone",2462},
	{"golfing_woman_dark_skin_tone",2463},
	{"man-golfing_light_skin_tone",2464},
	{"golfing_man_light_skin_tone",2465},
	{"man-golfing_medium_light_skin_tone",2466},
	{"golfing_man_medium_light_skin_tone",2467},
	{"man-golfing_medium_skin_tone",2468},
	{"golfing_man_medium_skin_tone",2469},
	{"man-golfing_medium_dark_skin_tone",2470},
	{"golfing_man_medium_dark_skin_tone",2471},
	{"man-golfing_dark_skin_tone",2472},
	{"golfing_man_dark_skin_tone",2473},
	{"golfer_light_skin_tone",2474},
	{"golfer_medium_light_skin_tone",2475},
	{"golfer_medium_skin_tone",2476},
	{"golfer_medium_dark_skin_tone",2477},
	{"golfer_dark_skin_tone",2478},
	{"ear_light_skin_tone",2479},
	{"ear_medium_light_skin_tone",2480},
	{"ear_medium_skin_tone",2481},
	{"ear_medium_dark_skin_tone",2482},
	{"ear_dark_skin_tone",2483},
	{"nose_light_skin_tone",2484},
	{"nose_medium_light_skin_tone",2485},
	{"nose_medium_skin_tone",2486},
	{"nose_medium_dark_skin_tone",2487},
	{"nose_dark_skin_tone",2488},
	{"point_up_2_light_skin_tone",2489},
	{"point_up_2_medium_light_skin_tone",2490},
	{"point_up_2_medium_skin_tone",2491},
	{"point_up_2_medium_dark_skin_tone",2492},
	{"point_up_2_dark_skin_tone",2493},
	{"point_down_light_skin_tone",2494},
	{"point_down_medium_light_skin_tone",2495},
	{"point_down_medium_skin_tone",2496},
	{"point_down_medium_dark_skin_tone",2497},
	{"point_down_dark_skin_tone",2498},
	{"point_left_light_skin_tone",2499},
	{"point_left_medium_light_skin_tone",2500},
	{"point_left_medium_skin_tone",2501},
	{"point_left_medium_dark_skin_tone",2502},
	{"point_left_dark_skin_tone",2503},
	{"point_right_light_skin_tone",2504},
	{"point_right_medium_light_skin_tone",2505},
	{"point_right_medium_skin_tone",2506},
	{"point_right_medium_dark_skin_tone",2507},
	{"point_right_dark_skin_tone",2508},
	{"facepunch_light_skin_tone",2509},
	{"punch_light_skin_tone",2510},
	{"fist_oncoming_light_skin_tone",2511},
	{"facepunch_medium_light_skin_tone",2512},
	{"punch_medium_light_skin_tone",2513},
	{"fist_oncoming_medium_light_skin_tone",2514},
	{"facepunch_medium_skin_tone",2515},
	{"punch_medium_skin_tone",2516},
	{"fist_oncoming_medium_skin_tone",2517},
	{"facepunch_medium_dark_skin_tone",2518},
	{"punch_medium_dark_skin_tone",2519},
	{"fist_oncoming_medium_dark_skin_tone",2520},
	{"facepunch_dark_skin_tone",2521},
	{"punch_dark_skin_tone",2522},
	{"fist_oncoming_dark_skin_tone",2523},
	{"wave_light_skin_tone",2524},
	{"wave_medium_light_skin_tone",2525},
	{"wave_medium_skin_tone",2526},
	{"wave_medium_dark_skin_tone",2527},
	{"wave_dark_skin_tone",2528},
	{"ok_hand_light_skin_tone",2529},
	{"ok_hand_medium_light_skin_tone",2530},
	{"ok_hand_medium_skin_tone",2531},
	{"ok_hand_medium_dark_skin_tone",2532},
	{"ok_hand_dark_skin_tone",2533},
	{"+1_light_skin_tone",2534},
	{"thumbsup_light_skin_tone",2535},
	{"+1_medium_light_skin_tone",2536},
	{"thumbsup_medium_light_skin_tone",2537},
	{"+1_medium_skin_tone",2538},
	{"thumbsup_medium_skin_tone",2539},
	{"+1_medium_dark_skin_tone",2540},
	{"thumbsup_medium_dark_skin_tone",2541},
	{"+1_dark_skin_tone",2542},
	{"thumbsup_dark_skin_tone",2543},
	{"-1_light_skin_tone",2544},
	{"thumbsdown_light_skin_tone",2545},
	{"-1_medium_light_skin_tone",2546},
	{"thumbsdown_medium_light_skin_tone",2547},
	{"-1_medium_skin_tone",2548},
	{"thumbsdown_medium_skin_tone",2549},
	{"-1_medium_dark_skin_tone",2550},
	{"thumbsdown_medium_dark_skin_tone",2551},
	{"-1_dark_skin_tone",2552},
	{"thumbsdown_dark_skin_tone",2553},
	{"clap_light_skin_tone",2554},
	{"clap_medium_light_skin_tone",2555},
	{"clap_medium_skin_tone",2556},
	{"clap_medium_dark_skin_tone",2557},
	{"clap_dark_skin_tone",2558},
	{"open_hands_light_skin_tone",2559},
	{"open_hands_medium_light_skin_tone",2560},
	{"open_hands_medium_skin_tone",2561},
	{"open_hands_medium_dark_skin_tone",2562},
	{"open_hands_dark_skin_tone",2563},
	{"boy_light_skin_tone",2564},
	{"boy_medium_light_skin_tone",2565},
	{"boy_medium_skin_tone",2566},
	{"boy_medium_dark_skin_tone",2567},
	{"boy_dark_skin_tone",2568},
	{"girl_light_skin_tone",2569},
	{"girl_medium_light_skin_tone",2570},
	{"girl_medium_skin_tone",2571},
	{"girl_medium_dark_skin_tone",2572},
	{"girl_dark_skin_tone",2573},
	{"male-farmer_light_skin_tone",2574},
	{"man_farmer_light_skin_tone",2575},
	{"male-farmer_medium_light_skin_tone",2576},
	{"man_farmer_medium_light_skin_tone",2577},
	{"male-farmer_medium_skin_tone",2578},
	{"man_farmer_medium_skin_tone",2579},
	{"male-farmer_medium_dark_skin_tone",2580},
	{"man_farmer_medium_dark_skin_tone",2581},
	{"male-farmer_dark_skin_tone",2582},
	{"man_farmer_dark_skin_tone",2583},
	{"male-cook_light_skin_tone",2584},
	{"man_cook_light_skin_tone",2585},
	{"male-cook_medium_light_skin_tone",2586},
	{"man_cook_medium_light_skin_tone",2587},
	{"male-cook_medium_skin_tone",2588},
	{"man_cook_medium_skin_tone",2589},
	{"male-cook_medium_dark_skin_tone",2590},
	{"man_cook_medium_dark_skin_tone",2591},
	{"male-cook_dark_skin_tone",2592},
	{"man_cook_dark_skin_tone",2593},
	{"man_feeding_baby_light_skin_tone",2594},
	{"man_feeding_baby_medium_light_skin_tone",2595},
	{"man_feeding_baby_medium_skin_tone",2596},
	{"man_feeding_baby_medium_dark_skin_tone",2597},
	{"man_feeding_baby_dark_skin_tone",2598},
	{"male-student_light_skin_tone",2599},
	{"man_student_light_skin_tone",2600},
	{"male-student_medium_light_skin_tone",2601},
	{"man_student_medium_light_skin_tone",2602},
	{"male-student_medium_skin_tone",2603},
	{"man_student_medium_skin_tone",2604},
	{"male-student_medium_dark_skin_tone",2605},
	{"man_student_medium_dark_skin_tone",2606},
	{"male-student_dark_skin_tone",2607},
	{"man_student_dark_skin_tone",2608},
	{"male-singer_light_skin_tone",2609},
	{"man_singer_light_skin_tone",2610},
	{"male-singer_medium_light_skin_tone",2611},
	{"man_singer_medium_light_skin_tone",2612},
	{"male-singer_medium_skin_tone",2613},
	{"man_singer_medium_skin_tone",2614},
	{"male-singer_medium_dark_skin_tone",2615},
	{"man_singer_medium_dark_skin_tone",2616},
	{"male-singer_dark_skin_tone",2617},
	{"man_singer_dark_skin_tone",2618},
	{"male-artist_light_skin_tone",2619},
	{"man_artist_light_skin_tone",2620},
	{"male-artist_medium_light_skin_tone",2621},
	{"man_artist_medium_light_skin_tone",2622},
	{"male-artist_medium_skin_tone",2623},
	{"man_artist_medium_skin_tone",2624},
	{"male-artist_medium_dark_skin_tone",2625},
	{"man_artist_medium_dark_skin_tone",2626},
	{"male-artist_dark_skin_tone",2627},
	{"man_artist_dark_skin_tone",2628},
	{"male-teacher_light_skin_tone",2629},
	{"man_teacher_light_skin_tone",2630},
	{"male-teacher_medium_light_skin_tone",2631},
	{"man_teacher_medium_light_skin_tone",2632},
	{"male-teacher_medium_skin_tone",2633},
	{"man_teacher_medium_skin_tone",2634},
	{"male-teacher_medium_dark_skin_tone",2635},
	{"man_teacher_medium_dark_skin_tone",2636},
	{"male-teacher_dark_skin_tone",2637},
	{"man_teacher_dark_skin_tone",2638},
	{"male-factory-worker_light_skin_tone",2639},
	{"man_factory_worker_light_skin_tone",2640},
	{"male-factory-worker_medium_light_skin_tone",2641},
	{"man_factory_worker_medium_light_skin_tone",2642},
	{"male-factory-worker_medium_skin_tone",2643},
	{"man_factory_worker_medium_skin_tone",2644},
	{"male-factory-worker_medium_dark_skin_tone",2645},
	{"man_factory_worker_medium_dark_skin_tone",2646},
	{"male-factory-worker_dark_skin_tone",2647},
	{"man_factory_worker_dark_skin_tone",2648},
	{"male-technologist_light_skin_tone",2649},
	{"man_technologist_light_skin_tone",2650},
	{"male-technologist_medium_light_skin_tone",2651},
	{"man_technologist_medium_light_skin_tone",2652},
	{"male-technologist_medium_skin_tone",2653},
	{"man_technologist_medium_skin_tone",2654},
	{"male-technologist_medium_dark_skin_tone",2655},
	{"man_technologist_medium_dark_skin_tone",2656},
	{"male-technologist_dark_skin_tone",2657},
	{"man_technologist_dark_skin_tone",2658},
	{"male-office-worker_light_skin_tone",2659},
	{"man_office_worker_light_skin_tone",2660},
	{"male-office-worker_medium_light_skin_tone",2661},
	{"man_office_worker_medium_light_skin_tone",2662},
	{"male-office-worker_medium_skin_tone",2663},
	{"man_office_worker_medium_skin_tone",2664},
	{"male-office-worker_medium_dark_skin_tone",2665},
	{"man_office_worker_medium_dark_skin_tone",2666},
	{"male-office-worker_dark_skin_tone",2667},
	{"man_office_worker_dark_skin_tone",2668},
	{"male-mechanic_light_skin_tone",2669},
	{"man_mechanic_light_skin_tone",2670},
	{"male-mechanic_medium_light_skin_tone",2671},
	{"man_mechanic_medium_light_skin_tone",2672},
	{"male-mechanic_medium_skin_tone",2673},
	{"man_mechanic_medium_skin_tone",2674},
	{"male-mechanic_medium_dark_skin_tone",2675},
	{"man_mechanic_medium_dark_skin_tone",2676},
	{"male-mechanic_dark_skin_tone",2677},
	{"man_mechanic_dark_skin_tone",2678},
	{"male-scientist_light_skin_tone",2679},
	{"man_scientist_light_skin_tone",2680},
	{"male-scientist_medium_light_skin_tone",2681},
	{"man_scientist_medium_light_skin_tone",2682},
	{"male-scientist_medium_skin_tone",2683},
	{"man_scientist_medium_skin_tone",2684},
	{"male-scientist_medium_dark_skin_tone",2685},
	{"man_scientist_medium_dark_skin_tone",2686},
	{"male-scientist_dark_skin_tone",2687},
	{"man_scientist_dark_skin_tone",2688},
	{"male-astronaut_light_skin_tone",2689},
	{"man_astronaut_light_skin_tone",2690},
	{"male-astronaut_medium_light_skin_tone",2691},
	{"man_astronaut_medium_light_skin_tone",2692},
	{"male-astronaut_medium_skin_tone",2693},
	{"man_astronaut_medium_skin_tone",2694},
	{"male-astronaut_medium_dark_skin_tone",2695},
	{"man_astronaut_medium_dark_skin_tone",2696},
	{"male-astronaut_dark_skin_tone",2697},
	{"man_astronaut_dark_skin_tone",2698},
	{"male-firefighter_light_skin_tone",2699},
	{"man_firefighter_light_skin_tone",2700},
	{"male-firefighter_medium_light_skin_tone",2701},
	{"man_firefighter_medium_light_skin_tone",2702},
	{"male-firefighter_medium_skin_tone",2703},
	{"man_firefighter_medium_skin_tone",2704},
	{"male-firefighter_medium_dark_skin_tone",2705},
	{"man_firefighter_medium_dark_skin_tone",2706},
	{"male-firefighter_dark_skin_tone",2707},
	{"man_firefighter_dark_skin_tone",2708},
	{"man_with_probing_cane_light_skin_tone",2709},
	{"man_with_probing_cane_medium_light_skin_tone",2710},
	{"man_with_probing_cane_medium_skin_tone",2711},
	{"man_with_probing_cane_medium_dark_skin_tone",2712},
	{"man_with_probing_cane_dark_skin_tone",2713},
	{"red_haired_man_light_skin_tone",2714},
	{"red_haired_man_medium_light_skin_tone",2715},
	{"red_haired_man_medium_skin_tone",2716},
	{"red_haired_man_medium_dark_skin_tone",2717},
	{"red_haired_man_dark_skin_tone",2718},
	{"curly_haired_man_light_skin_tone",2719},
	{"curly_haired_man_medium_light_skin_tone",2720},
	{"curly_haired_man_medium_skin_tone",2721},
	{"curly_haired_man_medium_dark_skin_tone",2722},
	{"curly_haired_man_dark_skin_tone",2723},
	{"bald_man_light_skin_tone",2724},
	{"bald_man_medium_light_skin_tone",2725},
	{"bald_man_medium_skin_tone",2726},
	{"bald_man_medium_dark_skin_tone",2727},
	{"bald_man_dark_skin_tone",2728},
	{"white_haired_man_light_skin_tone",2729},
	{"white_haired_man_medium_light_skin_tone",2730},
	{"white_haired_man_medium_skin_tone",2731},
	{"white_haired_man_medium_dark_skin_tone",2732},
	{"white_haired_man_dark_skin_tone",2733},
	{"man_in_motorized_wheelchair_light_skin_tone",2734},
	{"man_in_motorized_wheelchair_medium_light_skin_tone",2735},
	{"man_in_motorized_wheelchair_medium_skin_tone",2736},
	{"man_in_motorized_wheelchair_medium_dark_skin_tone",2737},
	{"man_in_motorized_wheelchair_dark_skin_tone",2738},
	{"man_in_manual_wheelchair_light_skin_tone",2739},
	{"man_in_manual_wheelchair_medium_light_skin_tone",2740},
	{"man_in_manual_wheelchair_medium_skin_tone",2741},
	{"man_in_manual_wheelchair_medium_dark_skin_tone",2742},
	{"man_in_manual_wheelchair_dark_skin_tone",2743},
	{"male-doctor_light_skin_tone",2744},
	{"man_health_worker_light_skin_tone",2745},
	{"male-doctor_medium_light_skin_tone",2746},
	{"man_health_worker_medium_light_skin_tone",2747},
	{"male-doctor_medium_skin_tone",2748},
	{"man_health_worker_medium_skin_tone",2749},
	{"male-doctor_medium_dark_skin_tone",2750},
	{"man_health_worker_medium_dark_skin_tone",2751},
	{"male-doctor_dark_skin_tone",2752},
	{"man_health_worker_dark_skin_tone",2753},
	{"male-judge_light_skin_tone",2754},
	{"man_judge_light_skin_tone",2755},
	{"male-judge_medium_light_skin_tone",2756},
	{"man_judge_medium_light_skin_tone",2757},
	{"male-judge_medium_skin_tone",2758},
	{"man_judge_medium_skin_tone",2759},
	{"male-judge_medium_dark_skin_tone",2760},
	{"man_judge_medium_dark_skin_tone",2761},
	{"male-judge_dark_skin_tone",2762},
	{"man_judge_dark_skin_tone",2763},
	{"male-pilot_light_skin_tone",2764},
	{"man_pilot_light_skin_tone",2765},
	{"male-pilot_medium_light_skin_tone",2766},
	{"man_pilot_medium_light_skin_tone",2767},
	{"male-pilot_medium_skin_tone",2768},
	{"man_pilot_medium_skin_tone",2769},
	{"male-pilot_medium_dark_skin_tone",2770},
	{"man_pilot_medium_dark_skin_tone",2771},
	{"male-pilot_dark_skin_tone",2772},
	{"man_pilot_dark_skin_tone",2773},
	{"man_light_skin_tone",2774},
	{"man_medium_light_skin_tone",2775},
	{"man_medium_skin_tone",2776},
	{"man_medium_dark_skin_tone",2777},
	{"man_dark_skin_tone",2778},
	{"female-farmer_light_skin_tone",2779},
	{"woman_farmer_light_skin_tone",2780},
	{"female-farmer_medium_light_skin_tone",2781},
	{"woman_farmer_medium_light_skin_tone",2782},
	{"female-farmer_medium_skin_tone",2783},
	{"woman_farmer_medium_skin_tone",2784},
	{"female-farmer_medium_dark_skin_tone",2785},
	{"woman_farmer_medium_dark_skin_tone",2786},
	{"female-farmer_dark_skin_tone",2787},
	{"woman_farmer_dark_skin_tone",2788},
	{"female-cook_light_skin_tone",2789},
	{"woman_cook_light_skin_tone",2790},
	{"female-cook_medium_light_skin_tone",2791},
	{"woman_cook_medium_light_skin_tone",2792},
	{"female-cook_medium_skin_tone",2793},
	{"woman_cook_medium_skin_tone",2794},
	{"female-cook_medium_dark_skin_tone",2795},
	{"woman_cook_medium_dark_skin_tone",2796},
	{"female-cook_dark_skin_tone",2797},
	{"woman_cook_dark_skin_tone",2798},
	{"woman_feeding_baby_light_skin_tone",2799},
	{"woman_feeding_baby_medium_light_skin_tone",2800},
	{"woman_feeding_baby_medium_skin_tone",2801},
	{"woman_feeding_baby_medium_dark_skin_tone",2802},
	{"woman_feeding_baby_dark_skin_tone",2803},
	{"female-student_light_skin_tone",2804},
	{"woman_student_light_skin_tone",2805},
	{"female-student_medium_light_skin_tone",2806},
	{"woman_student_medium_light_skin_tone",2807},
	{"female-student_medium_skin_tone",2808},
	{"woman_student_medium_skin_tone",2809},
	{"female-student_medium_dark_skin_tone",2810},
	{"woman_student_medium_dark_skin_tone",2811},
	{"female-student_dark_skin_tone",2812},
	{"woman_student_dark_skin_tone",2813},
	{"female-singer_light_skin_tone",2814},
	{"woman_singer_light_skin_tone",2815},
	{"female-singer_medium_light_skin_tone",2816},
	{"woman_singer_medium_light_skin_tone",2817},
	{"female-singer_medium_skin_tone",2818},
	{"woman_singer_medium_skin_tone",2819},
	{"female-singer_medium_dark_skin_tone",2820},
	{"woman_singer_medium_dark_skin_tone",2821},
	{"female-singer_dark_skin_tone",2822},
	{"woman_singer_dark_skin_tone",2823},
	{"female-artist_light_skin_tone",2824},
	{"woman_artist_light_skin_tone",2825},
	{"female-artist_medium_light_skin_tone",2826},
	{"woman_artist_medium_light_skin_tone",2827},
	{"female-artist_medium_skin_tone",2828},
	{"woman_artist_medium_skin_tone",2829},
	{"female-artist_medium_dark_skin_tone",2830},
	{"woman_artist_medium_dark_skin_tone",2831},
	{"female-artist_dark_skin_tone",2832},
	{"woman_artist_dark_skin_tone",2833},
	{"female-teacher_light_skin_tone",2834},
	{"woman_teacher_light_skin_tone",2835},
	{"female-teacher_medium_light_skin_tone",2836},
	{"woman_teacher_medium_light_skin_tone",2837},
	{"female-teacher_medium_skin_tone",2838},
	{"woman_teacher_medium_skin_tone",2839},
	{"female-teacher_medium_dark_skin_tone",2840},
	{"woman_teacher_medium_dark_skin_tone",2841},
	{"female-teacher_dark_skin_tone",2842},
	{"woman_teacher_dark_skin_tone",2843},
	{"female-factory-worker_light_skin_tone",2844},
	{"woman_factory_worker_light_skin_tone",2845},
	{"female-factory-worker_medium_light_skin_tone",2846},
	{"woman_factory_worker_medium_light_skin_tone",2847},
	{"female-factory-worker_medium_skin_tone",2848},
	{"woman_factory_worker_medium_skin_tone",2849},
	{"female-factory-worker_medium_dark_skin_tone",2850},
	{"woman_factory_worker_medium_dark_skin_tone",2851},
	{"female-factory-worker_dark_skin_tone",2852},
	{"woman_factory_worker_dark_skin_tone",2853},
	{"female-technologist_light_skin_tone",2854},
	{"woman_technologist_light_skin_tone",2855},
	{"female-technologist_medium_light_skin_tone",2856},
	{"woman_technologist_medium_light_skin_tone",2857},
	{"female-technologist_medium_skin_tone",2858},
	{"woman_technologist_medium_skin_tone",2859},
	{"female-technologist_medium_dark_skin_tone",2860},
	{"woman_technologist_medium_dark_skin_tone",2861},
	{"female-technologist_dark_skin_tone",2862},
	{"woman_technologist_dark_skin_tone",2863},
	{"female-office-worker_light_skin_tone",2864},
	{"woman_office_worker_light_skin_tone",2865},
	{"female-office-worker_medium_light_skin_tone",2866},
	{"woman_office_worker_medium_light_skin_tone",2867},
	{"female-office-worker_medium_skin_tone",2868},
	{"woman_office_worker_medium_skin_tone",2869},
	{"female-office-worker_medium_dark_skin_tone",2870},
	{"woman_office_worker_medium_dark_skin_tone",2871},
	{"female-office-worker_dark_skin_tone",2872},
	{"woman_office_worker_dark_skin_tone",2873},
	{"female-mechanic_light_skin_tone",2874},
	{"woman_mechanic_light_skin_tone",2875},
	{"female-mechanic_medium_light_skin_tone",2876},
	{"woman_mechanic_medium_light_skin_tone",2877},
	{"female-mechanic_medium_skin_tone",2878},
	{"woman_mechanic_medium_skin_tone",2879},
	{"female-mechanic_medium_dark_skin_tone",2880},
	{"woman_mechanic_medium_dark_skin_tone",2881},
	{"female-mechanic_dark_skin_tone",2882},
	{"woman_mechanic_dark_skin_tone",2883},
	{"female-scientist_light_skin_tone",2884},
	{"woman_scientist_light_skin_tone",2885},
	{"female-scientist_medium_light_skin_tone",2886},
	{"woman_scientist_medium_light_skin_tone",2887},
	{"female-scientist_medium_skin_tone",2888},
	{"woman_scientist_medium_skin_tone",2889},
	{"female-scientist_medium_dark_skin_tone",2890},
	{"woman_scientist_medium_dark_skin_tone",2891},
	{"female-scientist_dark_skin_tone",2892},
	{"woman_scientist_dark_skin_tone",2893},
	{"female-astronaut_light_skin_tone",2894},
	{"woman_astronaut_light_skin_tone",2895},
	{"female-astronaut_medium_light_skin_tone",2896},
	{"woman_astronaut_medium_light_skin_tone",2897},
	{"female-astronaut_medium_skin_tone",2898},
	{"woman_astronaut_medium_skin_tone",2899},
	{"female-astronaut_medium_dark_skin_tone",2900},
	{"woman_astronaut_medium_dark_skin_tone",2901},
	{"female-astronaut_dark_skin_tone",2902},
	{"woman_astronaut_dark_skin_tone",2903},
	{"female-firefighter_light_skin_tone",2904},
	{"woman_firefighter_light_skin_tone",2905},
	{"female-firefighter_medium_light_skin_tone",2906},
	{"woman_firefighter_medium_light_skin_tone",2907},
	{"female-firefighter_medium_skin_tone",2908},
	{"woman_firefighter_medium_skin_tone",2909},
	{"female-firefighter_medium_dark_skin_tone",2910},
	{"woman_firefighter_medium_dark_skin_tone",2911},
	{"female-firefighter_dark_skin_tone",2912},
	{"woman_firefighter_dark_skin_tone",2913},
	{"woman_with_probing_cane_light_skin_tone",2914},
	{"woman_with_probing_cane_medium_light_skin_tone",2915},
	{"woman_with_probing_cane_medium_skin_tone",2916},
	{"woman_with_probing_cane_medium_dark_skin_tone",2917},
	{"woman_with_probing_cane_dark_skin_tone",2918},
	{"red_haired_woman_light_skin_tone",2919},
	{"red_haired_woman_medium_light_skin_tone",2920},
	{"red_haired_woman_medium_skin_tone",2921},
	{"red_haired_woman_medium_dark_skin_tone",2922},
	{"red_haired_woman_dark_skin_tone",2923},
	{"curly_haired_woman_light_skin_tone",2924},
	{"curly_haired_woman_medium_light_skin_tone",2925},
	{"curly_haired_woman_medium_skin_tone",2926},
	{"curly_haired_woman_medium_dark_skin_tone",2927},
	{"curly_haired_woman_dark_skin_tone",2928},
	{"bald_woman_light_skin_tone",2929},
	{"bald_woman_medium_light_skin_tone",2930},
	{"bald_woman_medium_skin_tone",2931},
	{"bald_woman_medium_dark_skin_tone",2932},
	{"bald_woman_dark_skin_tone",2933},
	{"white_haired_woman_light_skin_tone",2934},
	{"white_haired_woman_medium_light_skin_tone",2935},
	{"white_haired_woman_medium_skin_tone",2936},
	{"white_haired_woman_medium_dark_skin_tone",2937},
	{"white_haired_woman_dark_skin_tone",2938},
	{"woman_in_motorized_wheelchair_light_skin_tone",2939},
	{"woman_in_motorized_wheelchair_medium_light_skin_tone",2940},
	{"woman_in_motorized_wheelchair_medium_skin_tone",2941},
	{"woman_in_motorized_wheelchair_medium_dark_skin_tone",2942},
	{"woman_in_motorized_wheelchair_dark_skin_tone",2943},
	{"woman_in_manual_wheelchair_light_skin_tone",2944},
	{"woman_in_manual_wheelchair_medium_light_skin_tone",2945},
	{"woman_in_manual_wheelchair_medium_skin_tone",2946},
	{"woman_in_manual_wheelchair_medium_dark_skin_tone",2947},
	{"woman_in_manual_wheelchair_dark_skin_tone",2948},
	{"female-doctor_light_skin_tone",2949},
	{"woman_health_worker_light_skin_tone",2950},
	{"female-doctor_medium_light_skin_tone",2951},
	{"woman_health_worker_medium_light_skin_tone",2952},
	{"female-doctor_medium_skin_tone",2953},
	{"woman_health_worker_medium_skin_tone",2954},
	{"female-doctor_medium_dark_skin_tone",2955},
	{"woman_health_worker_medium_dark_skin_tone",2956},
	{"female-doctor_dark_skin_tone",2957},
	{"woman_health_worker_dark_skin_tone",2958},
	{"female-judge_light_skin_tone",2959},
	{"woman_judge_light_skin_tone",2960},
	{"female-judge_medium_light_skin_tone",2961},
	{"woman_judge_medium_light_skin_tone",2962},
	{"female-judge_medium_skin_tone",2963},
	{"woman_judge_medium_skin_tone",2964},
	{"female-judge_medium_dark_skin_tone",2965},
	{"woman_judge_medium_dark_skin_tone",2966},
	{"female-judge_dark_skin_tone",2967},
	{"woman_judge_dark_skin_tone",2968},
	{"female-pilot_light_skin_tone",2969},
	{"woman_pilot_light_skin_tone",2970},
	{"female-pilot_medium_light_skin_tone",2971},
	{"woman_pilot_medium_light_skin_tone",2972},
	{"female-pilot_medium_skin_tone",2973},
	{"woman_pilot_medium_skin_tone",2974},
	{"female-pilot_medium_dark_skin_tone",2975},
	{"woman_pilot_medium_dark_skin_tone",2976},
	{"female-pilot_dark_skin_tone",2977},
	{"woman_pilot_dark_skin_tone",2978},
	{"woman_light_skin_tone",2979},
	{"woman_medium_light_skin_tone",2980},
	{"woman_medium_skin_tone",2981},
	{"woman_medium_dark_skin_tone",2982},
	{"woman_dark_skin_tone",2983},
	{"man_and_woman_holding_hands_light_skin_tone",2984},
	{"woman_and_man_holding_hands_light_skin_tone",2985},
	{"couple_light_skin_tone",2986},
	{"man_and_woman_holding_hands_medium_light_skin_tone",2987},
	{"woman_and_man_holding_hands_medium_light_skin_tone",2988},
	{"couple_medium_light_skin_tone",2989},
	{"man_and_woman_holding_hands_medium_skin_tone",2990},
	{"woman_and_man_holding_hands_medium_skin_tone",2991},
	{"couple_medium_skin_tone",2992},
	{"man_and_woman_holding_hands_medium_dark_skin_tone",2993},
	{"woman_and_man_holding_hands_medium_dark_skin_tone",2994},
	{"couple_medium_dark_skin_tone",2995},
	{"man_and_woman_holding_hands_dark_skin_tone",2996},
	{"woman_and_man_holding_hands_dark_skin_tone",2997},
	{"couple_dark_skin_tone",2998},
	{"man_and_woman_holding_hands_light_skin_tone_medium_light_skin_tone",2999},
	{"woman_and_man_holding_hands_light_skin_tone_medium_light_skin_tone",3000},
	{"couple_light_skin_tone_medium_light_skin_tone",3001},
	{"man_and_woman_holding_hands_light_skin_tone_medium_skin_tone",3002},
	{"woman_and_man_holding_hands_light_skin_tone_medium_skin_tone",3003},
	{"couple_light_skin_tone_medium_skin_tone",3004},
	{"man_and_woman_holding_hands_light_skin_tone_medium_dark_skin_tone",3005},
	{"woman_and_man_holding_hands_light_skin_tone_medium_dark_skin_tone",3006},
	{"couple_light_skin_tone_medium_dark_skin_tone",3007},
	{"man_and_woman_holding_hands_light_skin_tone_dark_skin_tone",3008},
	{"woman_and_man_holding_hands_light_skin_tone_dark_skin_tone",3009},
	{"couple_light_skin_tone_dark_skin_tone",3010},
	{"man_and_woman_holding_hands_medium_light_skin_tone_light_skin_tone",3011},
	{"woman_and_man_holding_hands_medium_light_skin_tone_light_skin_tone",3012},
	{"couple_medium_light_skin_tone_light_skin_tone",3013},
	{"man_and_woman_holding_hands_medium_light_skin_tone_medium_skin_tone",3014},
	{"woman_and_man_holding_hands_medium_light_skin_tone_medium_skin_tone",3015},
	{"couple_medium_light_skin_tone_medium_skin_tone",3016},
	{"man_and_woman_holding_hands_medium_light_skin_tone_medium_dark_skin_tone",3017},
	{"woman_and_man_holding_hands_medium_light_skin_tone_medium_dark_skin_tone",3018},
	{"couple_medium_light_skin_tone_medium_dark_skin_tone",3019},
	{"man_and_woman_holding_hands_medium_light_skin_tone_dark_skin_tone",3020},
	{"woman_and_man_holding_hands_medium_light_skin_tone_dark_skin_tone",3021},
	{"couple_medium_light_skin_tone_dark_skin_tone",3022},
	{"man_and_woman_holding_hands_medium_skin_tone_light_skin_tone",3023},
	{"woman_and_man_holding_hands_medium_skin_tone_light_skin_tone",3024},
	{"couple_medium_skin_tone_light_skin_tone",3025},
	{"man_and_woman_holding_hands_medium_skin_tone_medium_light_skin_tone",3026},
	{"woman_and_man_holding_hands_medium_skin_tone_medium_light_skin_tone",3027},
	{"couple_medium_skin_tone_medium_light_skin_tone",3028},
	{"man_and_woman_holding_hands_medium_skin_tone_medium_dark_skin_tone",3029},
	{"woman_and_man_holding_hands_medium_skin_tone_medium_dark_skin_tone",3030},
	{"couple_medium_skin_tone_medium_dark_skin_tone",3031},
	{"man_and_woman_holding_hands_medium_skin_tone_dark_skin_tone",3032},
	{"woman_and_man_holding_hands_medium_skin_tone_dark_skin_tone",3033},
	{"couple_medium_skin_tone_dark_skin_tone",3034},
	{"man_and_woman_holding_hands_medium_dark_skin_tone_light_skin_tone",3035},
	{"woman_and_man_holding_hands_medium_dark_skin_tone_light_skin_tone",3036},
	{"couple_medium_dark_skin_tone_light_skin_tone",3037},
	{"man_and_woman_holding_hands_medium_dark_skin_tone_medium_light_skin_tone",3038},
	{"woman_and_man_holding_hands_medium_dark_skin_tone_medium_light_skin_tone",3039},
	{"couple_medium_dark_skin_tone_medium_light_skin_tone",3040},
	{"man_and_woman_holding_hands_medium_dark_skin_tone_medium_skin_tone",3041},
	{"woman_and_man_holding_hands_medium_dark_skin_tone_medium_skin_tone",3042},
	{"couple_medium_dark_skin_tone_medium_skin_tone",3043},
	{"man_and_woman_holding_hands_medium_dark_skin_tone_dark_skin_tone",3044},
	{"woman_and_man_holding_hands_medium_dark_skin_tone_dark_skin_tone",3045},
	{"couple_medium_dark_skin_tone_dark_skin_tone",3046},
	{"man_and_woman_holding_hands_dark_skin_tone_light_skin_tone",3047},
	{"woman_and_man_holding_hands_dark_skin_tone_light_skin_tone",3048},
	{"couple_dark_skin_tone_light_skin_tone",3049},
	{"man_and_woman_holding_hands_dark_skin_tone_medium_light_skin_tone",3050},
	{"woman_and_man_holding_hands_dark_skin_tone_medium_light_skin_tone",3051},
	{"couple_dark_skin_tone_medium_light_skin_tone",3052},
	{"man_and_woman_holding_hands_dark_skin_tone_medium_skin_tone",3053},
	{"woman_and_man_holding_hands_dark_skin_tone_medium_skin_tone",3054},
	{"couple_dark_skin_tone_medium_skin_tone",3055},
	{"man_and_woman_holding_hands_dark_skin_tone_medium_dark_skin_tone",3056},
	{"woman_and_man_holding_hands_dark_skin_tone_medium_dark_skin_tone",3057},
	{"couple_dark_skin_tone_medium_dark_skin_tone",3058},
	{"two_men_holding_hands_light_skin_tone",3059},
	{"men_holding_hands_light_skin_tone",3060},
	{"two_men_holding_hands_medium_light_skin_tone",3061},
	{"men_holding_hands_medium_light_skin_tone",3062},
	{"two_men_holding_hands_medium_skin_tone",3063},
	{"men_holding_hands_medium_skin_tone",3064},
	{"two_men_holding_hands_medium_dark_skin_tone",3065},
	{"men_holding_hands_medium_dark_skin_tone",3066},
	{"two_men_holding_hands_dark_skin_tone",3067},
	{"men_holding_hands_dark_skin_tone",3068},
	{"two_men_holding_hands_light_skin_tone_medium_light_skin_tone",3069},
	{"men_holding_hands_light_skin_tone_medium_light_skin_tone",3070},
	{"two_men_holding_hands_light_skin_tone_medium_skin_tone",3071},
	{"men_holding_hands_light_skin_tone_medium_skin_tone",3072},
	{"two_men_holding_hands_light_skin_tone_medium_dark_skin_tone",3073},
	{"men_holding_hands_light_skin_tone_medium_dark_skin_tone",3074},
	{"two_men_holding_hands_light_skin_tone_dark_skin_tone",3075},
	{"men_holding_hands_light_skin_tone_dark_skin_tone",3076},
	{"two_men_holding_hands_medium_light_skin_tone_light_skin_tone",3077},
	{"men_holding_hands_medium_light_skin_tone_light_skin_tone",3078},
	{"two_men_holding_hands_medium_light_skin_tone_medium_skin_tone",3079},
	{"men_holding_hands_medium_light_skin_tone_medium_skin_tone",3080},
	{"two_men_holding_hands_medium_light_skin_tone_medium_dark_skin_tone",3081},
	{"men_holding_hands_medium_light_skin_tone_medium_dark_skin_tone",3082},
	{"two_men_holding_hands_medium_light_skin_tone_dark_skin_tone",3083},
	{"men_holding_hands_medium_light_skin_tone_dark_skin_tone",3084},
	{"two_men_holding_hands_medium_skin_tone_light_skin_tone",3085},
	{"men_holding_hands_medium_skin_tone_light_skin_tone",3086},
	{"two_men_holding_hands_medium_skin_tone_medium_light_skin_tone",3087},
	{"men_holding_hands_medium_skin_tone_medium_light_skin_tone",3088},
	{"two_men_holding_hands_medium_skin_tone_medium_dark_skin_tone",3089},
	{"men_holding_hands_medium_skin_tone_medium_dark_skin_tone",3090},
	{"two_men_holding_hands_medium_skin_tone_dark_skin_tone",3091},
	{"men_holding_hands_medium_skin_tone_dark_skin_tone",3092},
	{"two_men_holding_hands_medium_dark_skin_tone_light_skin_tone",3093},
	{"men_holding_hands_medium_dark_skin_tone_light_skin_tone",3094},
	{"two_men_holding_hands_medium_dark_skin_tone_medium_light_skin_tone",3095},
	{"men_holding_hands_medium_dark_skin_tone_medium_light_skin_tone",3096},
	{"two_men_holding_hands_medium_dark_skin_tone_medium_skin_tone",3097},
	{"men_holding_hands_medium_dark_skin_tone_medium_skin_tone",3098},
	{"two_men_holding_hands_medium_dark_skin_tone_dark_skin_tone",3099},
	{"men_holding_hands_medium_dark_skin_tone_dark_skin_tone",3100},
	{"two_men_holding_hands_dark_skin_tone_light_skin_tone",3101},
	{"men_holding_hands_dark_skin_tone_light_skin_tone",3102},
	{"two_men_holding_hands_dark_skin_tone_medium_light_skin_tone",3103},
	{"men_holding_hands_dark_skin_tone_medium_light_skin_tone",3104},
	{"two_men_holding_hands_dark_skin_tone_medium_skin_tone",3105},
	{"men_holding_hands_dark_skin_tone_medium_skin_tone",3106},
	{"two_men_holding_hands_dark_skin_tone_medium_dark_skin_tone",3107},
	{"men_holding_hands_dark_skin_tone_medium_dark_skin_tone",3108},
	{"two_women_holding_hands_light_skin_tone",3109},
	{"women_holding_hands_light_skin_tone",3110},
	{"two_women_holding_hands_medium_light_skin_tone",3111},
	{"women_holding_hands_medium_light_skin_tone",3112},
	{"two_women_holding_hands_medium_skin_tone",3113},
	{"women_holding_hands_medium_skin_tone",3114},
	{"two_women_holding_hands_medium_dark_skin_tone",3115},
	{"women_holding_hands_medium_dark_skin_tone",3116},
	{"two_women_holding_hands_dark_skin_tone",3117},
	{"women_holding_hands_dark_skin_tone",3118},
	{"two_women_holding_hands_light_skin_tone_medium_light_skin_tone",3119},
	{"women_holding_hands_light_skin_tone_medium_light_skin_tone",3120},
	{"two_women_holding_hands_light_skin_tone_medium_skin_tone",3121},
	{"women_holding_hands_light_skin_tone_medium_skin_tone",3122},
	{"two_women_holding_hands_light_skin_tone_medium_dark_skin_tone",3123},
	{"women_holding_hands_light_skin_tone_medium_dark_skin_tone",3124},
	{"two_women_holding_hands_light_skin_tone_dark_skin_tone",3125},
	{"women_holding_hands_light_skin_tone_dark_skin_tone",3126},
	{"two_women_holding_hands_medium_light_skin_tone_light_skin_tone",3127},
	{"women_holding_hands_medium_light_skin_tone_light_skin_tone",3128},
	{"two_women_holding_hands_medium_light_skin_tone_medium_skin_tone",3129},
	{"women_holding_hands_medium_light_skin_tone_medium_skin_tone",3130},
	{"two_women_holding_hands_medium_light_skin_tone_medium_dark_skin_tone",3131},
	{"women_holding_hands_medium_light_skin_tone_medium_dark_skin_tone",3132},
	{"two_women_holding_hands_medium_light_skin_tone_dark_skin_tone",3133},
	{"women_holding_hands_medium_light_skin_tone_dark_skin_tone",3134},
	{"two_women_holding_hands_medium_skin_tone_light_skin_tone",3135},
	{"women_holding_hands_medium_skin_tone_light_skin_tone",3136},
	{"two_women_holding_hands_medium_skin_tone_medium_light_skin_tone",3137},
	{"women_holding_hands_medium_skin_tone_medium_light_skin_tone",3138},
	{"two_women_holding_hands_medium_skin_tone_medium_dark_skin_tone",3139},
	{"women_holding_hands_medium_skin_tone_medium_dark_skin_tone",3140},
	{"two_women_holding_hands_medium_skin_tone_dark_skin_tone",3141},
	{"women_holding_hands_medium_skin_tone_dark_skin_tone",3142},
	{"two_women_holding_hands_medium_dark_skin_tone_light_skin_tone",3143},
	{"women_holding_hands_medium_dark_skin_tone_light_skin_tone",3144},
	{"two_women_holding_hands_medium_dark_skin_tone_medium_light_skin_tone",3145},
	{"women_holding_hands_medium_dark_skin_tone_medium_light_skin_tone",3146},
	{"two_women_holding_hands_medium_dark_skin_tone_medium_skin_tone",3147},
	{"women_holding_hands_medium_dark_skin_tone_medium_skin_tone",3148},
	{"two_women_holding_hands_medium_dark_skin_tone_dark_skin_tone",3149},
	{"women_holding_hands_medium_dark_skin_tone_dark_skin_tone",3150},
	{"two_women_holding_hands_dark_skin_tone_light_skin_tone",3151},
	{"women_holding_hands_dark_skin_tone_light_skin_tone",3152},
	{"two_women_holding_hands_dark_skin_tone_medium_light_skin_tone",3153},
	{"women_holding_hands_dark_skin_tone_medium_light_skin_tone",3154},
	{"two_women_holding_hands_dark_skin_tone_medium_skin_tone",3155},
	{"women_holding_hands_dark_skin_tone_medium_skin_tone",3156},
	{"two_women_holding_hands_dark_skin_tone_medium_dark_skin_tone",3157},
	{"women_holding_hands_dark_skin_tone_medium_dark_skin_tone",3158},
	{"female-police-officer_light_skin_tone",3159},
	{"policewoman_light_skin_tone",3160},
	{"female-police-officer_medium_light_skin_tone",3161},
	{"policewoman_medium_light_skin_tone",3162},
	{"female-police-officer_medium_skin_tone",3163},
	{"policewoman_medium_skin_tone",3164},
	{"female-police-officer_medium_dark_skin_tone",3165},
	{"policewoman_medium_dark_skin_tone",3166},
	{"female-police-officer_dark_skin_tone",3167},
	{"policewoman_dark_skin_tone",3168},
	{"male-police-officer_light_skin_tone",3169},
	{"policeman_light_skin_tone",3170},
	{"male-police-officer_medium_light_skin_tone",3171},
	{"policeman_medium_light_skin_tone",3172},
	{"male-police-officer_medium_skin_tone",3173},
	{"policeman_medium_skin_tone",3174},
	{"male-police-officer_medium_dark_skin_tone",3175},
	{"policeman_medium_dark_skin_tone",3176},
	{"male-police-officer_dark_skin_tone",3177},
	{"policeman_dark_skin_tone",3178},
	{"cop_light_skin_tone",3179},
	{"cop_medium_light_skin_tone",3180},
	{"cop_medium_skin_tone",3181},
	{"cop_medium_dark_skin_tone",3182},
	{"cop_dark_skin_tone",3183},
	{"woman_with_veil_light_skin_tone",3184},
	{"woman_with_veil_medium_light_skin_tone",3185},
	{"woman_with_veil_medium_skin_tone",3186},
	{"woman_with_veil_medium_dark_skin_tone",3187},
	{"woman_with_veil_dark_skin_tone",3188},
	{"man_with_veil_light_skin_tone",3189},
	{"man_with_veil_medium_light_skin_tone",3190},
	{"man_with_veil_medium_skin_tone",3191},
	{"man_with_veil_medium_dark_skin_tone",3192},
	{"man_with_veil_dark_skin_tone",3193},
	{"bride_with_veil_light_skin_tone",3194},
	{"bride_with_veil_medium_light_skin_tone",3195},
	{"bride_with_veil_medium_skin_tone",3196},
	{"bride_with_veil_medium_dark_skin_tone",3197},
	{"bride_with_veil_dark_skin_tone",3198},
	{"blond-haired-woman_light_skin_tone",3199},
	{"blonde_woman_light_skin_tone",3200},
	{"blond-haired-woman_medium_light_skin_tone",3201},
	{"blonde_woman_medium_light_skin_tone",3202},
	{"blond-haired-woman_medium_skin_tone",3203},
	{"blonde_woman_medium_skin_tone",3204},
	{"blond-haired-woman_medium_dark_skin_tone",3205},
	{"blonde_woman_medium_dark_skin_tone",3206},
	{"blond-haired-woman_dark_skin_tone",3207},
	{"blonde_woman_dark_skin_tone",3208},
	{"blond-haired-man_light_skin_tone",3209},
	{"blonde_man_light_skin_tone",3210},
	{"blond-haired-man_medium_light_skin_tone",3211},
	{"blonde_man_medium_light_skin_tone",3212},
	{"blond-haired-man_medium_skin_tone",3213},
	{"blonde_man_medium_skin_tone",3214},
	{"blond-haired-man_medium_dark_skin_tone",3215},
	{"blonde_man_medium_dark_skin_tone",3216},
	{"blond-haired-man_dark_skin_tone",3217},
	{"blonde_man_dark_skin_tone",3218},
	{"person_with_blond_hair_light_skin_tone",3219},
	{"person_with_blond_hair_medium_light_skin_tone",3220},
	{"person_with_blond_hair_medium_skin_tone",3221},
	{"person_with_blond_hair_medium_dark_skin_tone",3222},
	{"person_with_blond_hair_dark_skin_tone",3223},
	{"man_with_gua_pi_mao_light_skin_tone",3224},
	{"man_with_gua_pi_mao_medium_light_skin_tone",3225},
	{"man_with_gua_pi_mao_medium_skin_tone",3226},
	{"man_with_gua_pi_mao_medium_dark_skin_tone",3227},
	{"man_with_gua_pi_mao_dark_skin_tone",3228},
	{"woman-wearing-turban_light_skin_tone",3229},
	{"woman_with_turban_light_skin_tone",3230},
	{"woman-wearing-turban_medium_light_skin_tone",3231},
	{"woman_with_turban_medium_light_skin_tone",3232},
	{"woman-wearing-turban_medium_skin_tone",3233},
	{"woman_with_turban_medium_skin_tone",3234},
	{"woman-wearing-turban_medium_dark_skin_tone",3235},
	{"woman_with_turban_medium_dark_skin_tone",3236},
	{"woman-wearing-turban_dark_skin_tone",3237},
	{"woman_with_turban_dark_skin_tone",3238},
	{"man-wearing-turban_light_skin_tone",3239},
	{"man-wearing-turban_medium_light_skin_tone",3240},
	{"man-wearing-turban_medium_skin_tone",3241},
	{"man-wearing-turban_medium_dark_skin_tone",3242},
	{"man-wearing-turban_dark_skin_tone",3243},
	{"man_with_turban_light_skin_tone",3244},
	{"man_with_turban_medium_light_skin_tone",3245},
	{"man_with_turban_medium_skin_tone",3246},
	{"man_with_turban_medium_dark_skin_tone",3247},
	{"man_with_turban_dark_skin_tone",3248},
	{"older_man_light_skin_tone",3249},
	{"older_man_medium_light_skin_tone",3250},
	{"older_man_medium_skin_tone",3251},
	{"older_man_medium_dark_skin_tone",3252},
	{"older_man_dark_skin_tone",3253},
	{"older_woman_light_skin_tone",3254},
	{"older_woman_medium_light_skin_tone",3255},
	{"older_woman_medium_skin_tone",3256},
	{"older_woman_medium_dark_skin_tone",3257},
	{"older_woman_dark_skin_tone",3258},
	{"baby_light_skin_tone",3259},
	{"baby_medium_light_skin_tone",3260},
	{"baby_medium_skin_tone",3261},
	{"baby_medium_dark_skin_tone",3262},
	{"baby_dark_skin_tone",3263},
	{"female-construction-worker_light_skin_tone",3264},
	{"construction_worker_woman_light_skin_tone",3265},
	{"female-construction-worker_medium_light_skin_tone",3266},
	{"construction_worker_woman_medium_light_skin_tone",3267},
	{"female-construction-worker_medium_skin_tone",3268},
	{"construction_worker_woman_medium_skin_tone",3269},
	{"female-construction-worker_medium_dark_skin_tone",3270},
	{"construction_worker_woman_medium_dark_skin_tone",3271},
	{"female-construction-worker_dark_skin_tone",3272},
	{"construction_worker_woman_dark_skin_tone",3273},
	{"male-construction-worker_light_skin_tone",3274},
	{"construction_worker_man_light_skin_tone",3275},
	{"male-construction-worker_medium_light_skin_tone",3276},
	{"construction_worker_man_medium_light_skin_tone",3277},
	{"male-construction-worker_medium_skin_tone",3278},
	{"construction_worker_man_medium_skin_tone",3279},
	{"male-construction-worker_medium_dark_skin_tone",3280},
	{"construction_worker_man_medium_dark_skin_tone",3281},
	{"male-construction-worker_dark_skin_tone",3282},
	{"construction_worker_man_dark_skin_tone",3283},
	{"construction_worker_light_skin_tone",3284},
	{"construction_worker_medium_light_skin_tone",3285},
	{"construction_worker_medium_skin_tone",3286},
	{"construction_worker_medium_dark_skin_tone",3287},
	{"construction_worker_dark_skin_tone",3288},
	{"princess_light_skin_tone",3289},
	{"princess_medium_light_skin_tone",3290},
	{"princess_medium_skin_tone",3291},
	{"princess_medium_dark_skin_tone",3292},
	{"princess_dark_skin_tone",3293},
	{"angel_light_skin_tone",3294},
	{"angel_medium_light_skin_tone",3295},
	{"angel_medium_skin_tone",3296},
	{"angel_medium_dark_skin_tone",3297},
	{"angel_dark_skin_tone",3298},
	{"woman-tipping-hand_light_skin_tone",3299},
	{"tipping_hand_woman_light_skin_tone",3300},
	{"woman-tipping-hand_medium_light_skin_tone",3301},
	{"tipping_hand_woman_medium_light_skin_tone",3302},
	{"woman-tipping-hand_medium_skin_tone",3303},
	{"tipping_hand_woman_medium_skin_tone",3304},
	{"woman-tipping-hand_medium_dark_skin_tone",3305},
	{"tipping_hand_woman_medium_dark_skin_tone",3306},
	{"woman-tipping-hand_dark_skin_tone",3307},
	{"tipping_hand_woman_dark_skin_tone",3308},
	{"man-tipping-hand_light_skin_tone",3309},
	{"tipping_hand_man_light_skin_tone",3310},
	{"man-tipping-hand_medium_light_skin_tone",3311},
	{"tipping_hand_man_medium_light_skin_tone",3312},
	{"man-tipping-hand_medium_skin_tone",3313},
	{"tipping_hand_man_medium_skin_tone",3314},
	{"man-tipping-hand_medium_dark_skin_tone",3315},
	{"tipping_hand_man_medium_dark_skin_tone",3316},
	{"man-tipping-hand_dark_skin_tone",3317},
	{"tipping_hand_man_dark_skin_tone",3318},
	{"information_desk_person_light_skin_tone",3319},
	{"information_desk_person_medium_light_skin_tone",3320},
	{"information_desk_person_medium_skin_tone",3321},
	{"information_desk_person_medium_dark_skin_tone",3322},
	{"information_desk_person_dark_skin_tone",3323},
	{"female-guard_light_skin_tone",3324},
	{"guardswoman_light_skin_tone",3325},
	{"female-guard_medium_light_skin_tone",3326},
	{"guardswoman_medium_light_skin_tone",3327},
	{"female-guard_medium_skin_tone",3328},
	{"guardswoman_medium_skin_tone",3329},
	{"female-guard_medium_dark_skin_tone",3330},
	{"guardswoman_medium_dark_skin_tone",3331},
	{"female-guard_dark_skin_tone",3332},
	{"guardswoman_dark_skin_tone",3333},
	{"male-guard_light_skin_tone",3334},
	{"male-guard_medium_light_skin_tone",3335},
	{"male-guard_medium_skin_tone",3336},
	{"male-guard_medium_dark_skin_tone",3337},
	{"male-guard_dark_skin_tone",3338},
	{"guardsman_light_skin_tone",3339},
	{"guardsman_medium_light_skin_tone",3340},
	{"guardsman_medium_skin_tone",3341},
	{"guardsman_medium_dark_skin_tone",3342},
	{"guardsman_dark_skin_tone",3343},
	{"dancer_light_skin_tone",3344},
	{"dancer_medium_light_skin_tone",3345},
	{"dancer_medium_skin_tone",3346},
	{"dancer_medium_dark_skin_tone",3347},
	{"dancer_dark_skin_tone",3348},
	{"nail_care_light_skin_tone",3349},
	{"nail_care_medium_light_skin_tone",3350},
	{"nail_care_medium_skin_tone",3351},
	{"nail_care_medium_dark_skin_tone",3352},
	{"nail_care_dark_skin_tone",3353},
	{"woman-getting-massage_light_skin_tone",3354},
	{"massage_woman_light_skin_tone",3355},
	{"woman-getting-massage_medium_light_skin_tone",3356},
	{"massage_woman_medium_light_skin_tone",3357},
	{"woman-getting-massage_medium_skin_tone",3358},
	{"massage_woman_medium_skin_tone",3359},
	{"woman-getting-massage_medium_dark_skin_tone",3360},
	{"massage_woman_medium_dark_skin_tone",3361},
	{"woman-getting-massage_dark_skin_tone",3362},
	{"massage_woman_dark_skin_tone",3363},
	{"man-getting-massage_light_skin_tone",3364},
	{"massage_man_light_skin_tone",3365},
	{"man-getting-massage_medium_light_skin_tone",3366},
	{"massage_man_medium_light_skin_tone",3367},
	{"man-getting-massage_medium_skin_tone",3368},
	{"massage_man_medium_skin_tone",3369},
	{"man-getting-massage_medium_dark_skin_tone",3370},
	{"massage_man_medium_dark_skin_tone",3371},
	{"man-getting-massage_dark_skin_tone",3372},
	{"massage_man_dark_skin_tone",3373},
	{"massage_light_skin_tone",3374},
	{"massage_medium_light_skin_tone",3375},
	{"massage_medium_skin_tone",3376},
	{"massage_medium_dark_skin_tone",3377},
	{"massage_dark_skin_tone",3378},
	{"woman-getting-haircut_light_skin_tone",3379},
	{"haircut_woman_light_skin_tone",3380},
	{"woman-getting-haircut_medium_light_skin_tone",3381},
	{"haircut_woman_medium_light_skin_tone",3382},
	{"woman-getting-haircut_medium_skin_tone",3383},
	{"haircut_woman_medium_skin_tone",3384},
	{"woman-getting-haircut_medium_dark_skin_tone",3385},
	{"haircut_woman_medium_dark_skin_tone",3386},
	{"woman-getting-haircut_dark_skin_tone",3387},
	{"haircut_woman_dark_skin_tone",3388},
	{"man-getting-haircut_light_skin_tone",3389},
	{"haircut_man_light_skin_tone",3390},
	{"man-getting-haircut_medium_light_skin_tone",3391},
	{"haircut_man_medium_light_skin_tone",3392},
	{"man-getting-haircut_medium_skin_tone",3393},
	{"haircut_man_medium_skin_tone",3394},
	{"man-getting-haircut_medium_dark_skin_tone",3395},
	{"haircut_man_medium_dark_skin_tone",3396},
	{"man-getting-haircut_dark_skin_tone",3397},
	{"haircut_man_dark_skin_tone",3398},
	{"haircut_light_skin_tone",3399},
	{"haircut_medium_light_skin_tone",3400},
	{"haircut_medium_skin_tone",3401},
	{"haircut_medium_dark_skin_tone",3402},
	{"haircut_dark_skin_tone",3403},
	{"muscle_light_skin_tone",3404},
	{"muscle_medium_light_skin_tone",3405},
	{"muscle_medium_skin_tone",3406},
	{"muscle_medium_dark_skin_tone",3407},
	{"muscle_dark_skin_tone",3408},
	{"man_in_business_suit_levitating_light_skin_tone",3409},
	{"business_suit_levitating_light_skin_tone",3410},
	{"man_in_business_suit_levitating_medium_light_skin_tone",3411},
	{"business_suit_levitating_medium_light_skin_tone",3412},
	{"man_in_business_suit_levitating_medium_skin_tone",3413},
	{"business_suit_levitating_medium_skin_tone",3414},
	{"man_in_business_suit_levitating_medium_dark_skin_tone",3415},
	{"business_suit_levitating_medium_dark_skin_tone",3416},
	{"man_in_business_suit_levitating_dark_skin_tone",3417},
	{"business_suit_levitating_dark_skin_tone",3418},
	{"female-detective_light_skin_tone",3419},
	{"female_detective_light_skin_tone",3420},
	{"female-detective_medium_light_skin_tone",3421},
	{"female_detective_medium_light_skin_tone",3422},
	{"female-detective_medium_skin_tone",3423},
	{"female_detective_medium_skin_tone",3424},
	{"female-detective_medium_dark_skin_tone",3425},
	{"female_detective_medium_dark_skin_tone",3426},
	{"female-detective_dark_skin_tone",3427},
	{"female_detective_dark_skin_tone",3428},
	{"male-detective_light_skin_tone",3429},
	{"male_detective_light_skin_tone",3430},
	{"male-detective_medium_light_skin_tone",3431},
	{"male_detective_medium_light_skin_tone",3432},
	{"male-detective_medium_skin_tone",3433},
	{"male_detective_medium_skin_tone",3434},
	{"male-detective_medium_dark_skin_tone",3435},
	{"male_detective_medium_dark_skin_tone",3436},
	{"male-detective_dark_skin_tone",3437},
	{"male_detective_dark_skin_tone",3438},
	{"sleuth_or_spy_light_skin_tone",3439},
	{"sleuth_or_spy_medium_light_skin_tone",3440},
	{"sleuth_or_spy_medium_skin_tone",3441},
	{"sleuth_or_spy_medium_dark_skin_tone",3442},
	{"sleuth_or_spy_dark_skin_tone",3443},
	{"man_dancing_light_skin_tone",3444},
	{"man_dancing_medium_light_skin_tone",3445},
	{"man_dancing_medium_skin_tone",3446},
	{"man_dancing_medium_dark_skin_tone",3447},
	{"man_dancing_dark_skin_tone",3448},
	{"raised_hand_with_fingers_splayed_light_skin_tone",3449},
	{"raised_hand_with_fingers_splayed_medium_light_skin_tone",3450},
	{"raised_hand_with_fingers_splayed_medium_skin_tone",3451},
	{"raised_hand_with_fingers_splayed_medium_dark_skin_tone",3452},
	{"raised_hand_with_fingers_splayed_dark_skin_tone",3453},
	{"middle_finger_light_skin_tone",3454},
	{"reversed_hand_with_middle_finger_extended_light_skin_tone",3455},
	{"middle_finger_medium_light_skin_tone",3456},
	{"reversed_hand_with_middle_finger_extended_medium_light_skin_tone",3457},
	{"middle_finger_medium_skin_tone",3458},
	{"reversed_hand_with_middle_finger_extended_medium_skin_tone",3459},
	{"middle_finger_medium_dark_skin_tone",3460},
	{"reversed_hand_with_middle_finger_extended_medium_dark_skin_tone",3461},
	{"middle_finger_dark_skin_tone",3462},
	{"reversed_hand_with_middle_finger_extended_dark_skin_tone",3463},
	{"spock-hand_light_skin_tone",3464},
	{"vulcan_salute_light_skin_tone",3465},
	{"spock-hand_medium_light_skin_tone",3466},
	{"vulcan_salute_medium_light_skin_tone",3467},
	{"spock-hand_medium_skin_tone",3468},
	{"vulcan_salute_medium_skin_tone",3469},
	{"spock-hand_medium_dark_skin_tone",3470},
	{"vulcan_salute_medium_dark_skin_tone",3471},
	{"spock-hand_dark_skin_tone",3472},
	{"vulcan_salute_dark_skin_tone",3473},
	{"woman-gesturing-no_light_skin_tone",3474},
	{"no_good_woman_light_skin_tone",3475},
	{"woman-gesturing-no_medium_light_skin_tone",3476},
	{"no_good_woman_medium_light_skin_tone",3477},
	{"woman-gesturing-no_medium_skin_tone",3478},
	{"no_good_woman_medium_skin_tone",3479},
	{"woman-gesturing-no_medium_dark_skin_tone",3480},
	{"no_good_woman_medium_dark_skin_tone",3481},
	{"woman-gesturing-no_dark_skin_tone",3482},
	{"no_good_woman_dark_skin_tone",3483},
	{"man-gesturing-no_light_skin_tone",3484},
	{"no_good_man_light_skin_tone",3485},
	{"man-gesturing-no_medium_light_skin_tone",3486},
	{"no_good_man_medium_light_skin_tone",3487},
	{"man-gesturing-no_medium_skin_tone",3488},
	{"no_good_man_medium_skin_tone",3489},
	{"man-gesturing-no_medium_dark_skin_tone",3490},
	{"no_good_man_medium_dark_skin_tone",3491},
	{"man-gesturing-no_dark_skin_tone",3492},
	{"no_good_man_dark_skin_tone",3493},
	{"no_good_light_skin_tone",3494},
	{"no_good_medium_light_skin_tone",3495},
	{"no_good_medium_skin_tone",3496},
	{"no_good_medium_dark_skin_tone",3497},
	{"no_good_dark_skin_tone",3498},
	{"woman-gesturing-ok_light_skin_tone",3499},
	{"woman-gesturing-ok_medium_light_skin_tone",3500},
	{"woman-gesturing-ok_medium_skin_tone",3501},
	{"woman-gesturing-ok_medium_dark_skin_tone",3502},
	{"woman-gesturing-ok_dark_skin_tone",3503},
	{"man-gesturing-ok_light_skin_tone",3504},
	{"ok_man_light_skin_tone",3505},
	{"man-gesturing-ok_medium_light_skin_tone",3506},
	{"ok_man_medium_light_skin_tone",3507},
	{"man-gesturing-ok_medium_skin_tone",3508},
	{"ok_man_medium_skin_tone",3509},
	{"man-gesturing-ok_medium_dark_skin_tone",3510},
	{"ok_man_medium_dark_skin_tone",3511},
	{"man-gesturing-ok_dark_skin_tone",3512},
	{"ok_man_dark_skin_tone",3513},
	{"ok_woman_light_skin_tone",3514},
	{"ok_woman_medium_light_skin_tone",3515},
	{"ok_woman_medium_skin_tone",3516},
	{"ok_woman_medium_dark_skin_tone",3517},
	{"ok_woman_dark_skin_tone",3518},
	{"woman-bowing_light_skin_tone",3519},
	{"bowing_woman_light_skin_tone",3520},
	{"woman-bowing_medium_light_skin_tone",3521},
	{"bowing_woman_medium_light_skin_tone",3522},
	{"woman-bowing_medium_skin_tone",3523},
	{"bowing_woman_medium_skin_tone",3524},
	{"woman-bowing_medium_dark_skin_tone",3525},
	{"bowing_woman_medium_dark_skin_tone",3526},
	{"woman-bowing_dark_skin_tone",3527},
	{"bowing_woman_dark_skin_tone",3528},
	{"man-bowing_light_skin_tone",3529},
	{"bowing_man_light_skin_tone",3530},
	{"man-bowing_medium_light_skin_tone",3531},
	{"bowing_man_medium_light_skin_tone",3532},
	{"man-bowing_medium_skin_tone",3533},
	{"bowing_man_medium_skin_tone",3534},
	{"man-bowing_medium_dark_skin_tone",3535},
	{"bowing_man_medium_dark_skin_tone",3536},
	{"man-bowing_dark_skin_tone",3537},
	{"bowing_man_dark_skin_tone",3538},
	{"bow_light_skin_tone",3539},
	{"bow_medium_light_skin_tone",3540},
	{"bow_medium_skin_tone",3541},
	{"bow_medium_dark_skin_tone",3542},
	{"bow_dark_skin_tone",3543},
	{"woman-raising-hand_light_skin_tone",3544},
	{"raising_hand_woman_light_skin_tone",3545},
	{"woman-raising-hand_medium_light_skin_tone",3546},
	{"raising_hand_woman_medium_light_skin_tone",3547},
	{"woman-raising-hand_medium_skin_tone",3548},
	{"raising_hand_woman_medium_skin_tone",3549},
	{"woman-raising-hand_medium_dark_skin_tone",3550},
	{"raising_hand_woman_medium_dark_skin_tone",3551},
	{"woman-raising-hand_dark_skin_tone",3552},
	{"raising_hand_woman_dark_skin_tone",3553},
	{"man-raising-hand_light_skin_tone",3554},
	{"raising_hand_man_light_skin_tone",3555},
	{"man-raising-hand_medium_light_skin_tone",3556},
	{"raising_hand_man_medium_light_skin_tone",3557},
	{"man-raising-hand_medium_skin_tone",3558},
	{"raising_hand_man_medium_skin_tone",3559},
	{"man-raising-hand_medium_dark_skin_tone",3560},
	{"raising_hand_man_medium_dark_skin_tone",3561},
	{"man-raising-hand_dark_skin_tone",3562},
	{"raising_hand_man_dark_skin_tone",3563},
	{"raising_hand_light_skin_tone",3564},
	{"raising_hand_medium_light_skin_tone",3565},
	{"raising_hand_medium_skin_tone",3566},
	{"raising_hand_medium_dark_skin_tone",3567},
	{"raising_hand_dark_skin_tone",3568},
	{"raised_hands_light_skin_tone",3569},
	{"raised_hands_medium_light_skin_tone",3570},
	{"raised_hands_medium_skin_tone",3571},
	{"raised_hands_medium_dark_skin_tone",3572},
	{"raised_hands_dark_skin_tone",3573},
	{"woman-frowning_light_skin_tone",3574},
	{"frowning_woman_light_skin_tone",3575},
	{"woman-frowning_medium_light_skin_tone",3576},
	{"frowning_woman_medium_light_skin_tone",3577},
	{"woman-frowning_medium_skin_tone",3578},
	{"frowning_woman_medium_skin_tone",3579},
	{"woman-frowning_medium_dark_skin_tone",3580},
	{"frowning_woman_medium_dark_skin_tone",3581},
	{"woman-frowning_dark_skin_tone",3582},
	{"frowning_woman_dark_skin_tone",3583},
	{"man-frowning_light_skin_tone",3584},
	{"frowning_man_light_skin_tone",3585},
	{"man-frowning_medium_light_skin_tone",3586},
	{"frowning_man_medium_light_skin_tone",3587},
	{"man-frowning_medium_skin_tone",3588},
	{"frowning_man_medium_skin_tone",3589},
	{"man-frowning_medium_dark_skin_tone",3590},
	{"frowning_man_medium_dark_skin_tone",3591},
	{"man-frowning_dark_skin_tone",3592},
	{"frowning_man_dark_skin_tone",3593},
	{"person_frowning_light_skin_tone",3594},
	{"person_frowning_medium_light_skin_tone",3595},
	{"person_frowning_medium_skin_tone",3596},
	{"person_frowning_medium_dark_skin_tone",3597},
	{"person_frowning_dark_skin_tone",3598},
	{"woman-pouting_light_skin_tone",3599},
	{"pouting_woman_light_skin_tone",3600},
	{"woman-pouting_medium_light_skin_tone",3601},
	{"pouting_woman_medium_light_skin_tone",3602},
	{"woman-pouting_medium_skin_tone",3603},
	{"pouting_woman_medium_skin_tone",3604},
	{"woman-pouting_medium_dark_skin_tone",3605},
	{"pouting_woman_medium_dark_skin_tone",3606},
	{"woman-pouting_dark_skin_tone",3607},
	{"pouting_woman_dark_skin_tone",3608},
	{"man-pouting_light_skin_tone",3609},
	{"pouting_man_light_skin_tone",3610},
	{"man-pouting_medium_light_skin_tone",3611},
	{"pouting_man_medium_light_skin_tone",3612},
	{"man-pouting_medium_skin_tone",3613},
	{"pouting_man_medium_skin_tone",3614},
	{"man-pouting_medium_dark_skin_tone",3615},
	{"pouting_man_medium_dark_skin_tone",3616},
	{"man-pouting_dark_skin_tone",3617},
	{"pouting_man_dark_skin_tone",3618},
	{"person_with_pouting_face_light_skin_tone",3619},
	{"person_with_pouting_face_medium_light_skin_tone",3620},
	{"person_with_pouting_face_medium_skin_tone",3621},
	{"person_with_pouting_face_medium_dark_skin_tone",3622},
	{"person_with_pouting_face_dark_skin_tone",3623},
	{"pray_light_skin_tone",3624},
	{"pray_medium_light_skin_tone",3625},
	{"pray_medium_skin_tone",3626},
	{"pray_medium_dark_skin_tone",3627},
	{"pray_dark_skin_tone",3628},
	{"woman-rowing-boat_light_skin_tone",3629},
	{"rowing_woman_light_skin_tone",3630},
	{"woman-rowing-boat_medium_light_skin_tone",3631},
	{"rowing_woman_medium_light_skin_tone",3632},
	{"woman-rowing-boat_medium_skin_tone",3633},
	{"rowing_woman_medium_skin_tone",3634},
	{"woman-rowing-boat_medium_dark_skin_tone",3635},
	{"rowing_woman_medium_dark_skin_tone",3636},
	{"woman-rowing-boat_dark_skin_tone",3637},
	{"rowing_woman_dark_skin_tone",3638},
	{"man-rowing-boat_light_skin_tone",3639},
	{"rowing_man_light_skin_tone",3640},
	{"man-rowing-boat_medium_light_skin_tone",3641},
	{"rowing_man_medium_light_skin_tone",3642},
	{"man-rowing-boat_medium_skin_tone",3643},
	{"rowing_man_medium_skin_tone",3644},
	{"man-rowing-boat_medium_dark_skin_tone",3645},
	{"rowing_man_medium_dark_skin_tone",3646},
	{"man-rowing-boat_dark_skin_tone",3647},
	{"rowing_man_dark_skin_tone",3648},
	{"rowboat_light_skin_tone",3649},
	{"rowboat_medium_light_skin_tone",3650},
	{"rowboat_medium_skin_tone",3651},
	{"rowboat_medium_dark_skin_tone",3652},
	{"rowboat_dark_skin_tone",3653},
	{"woman-biking_light_skin_tone",3654},
	{"biking_woman_light_skin_tone",3655},
	{"woman-biking_medium_light_skin_tone",3656},
	{"biking_woman_medium_light_skin_tone",3657},
	{"woman-biking_medium_skin_tone",3658},
	{"biking_woman_medium_skin_tone",3659},
	{"woman-biking_medium_dark_skin_tone",3660},
	{"biking_woman_medium_dark_skin_tone",3661},
	{"woman-biking_dark_skin_tone",3662},
	{"biking_woman_dark_skin_tone",3663},
	{"man-biking_light_skin_tone",3664},
	{"biking_man_light_skin_tone",3665},
	{"man-biking_medium_light_skin_tone",3666},
	{"biking_man_medium_light_skin_tone",3667},
	{"man-biking_medium_skin_tone",3668},
	{"biking_man_medium_skin_tone",3669},
	{"man-biking_medium_dark_skin_tone",3670},
	{"biking_man_medium_dark_skin_tone",3671},
	{"man-biking_dark_skin_tone",3672},
	{"biking_man_dark_skin_tone",3673},
	{"bicyclist_light_skin_tone",3674},
	{"bicyclist_medium_light_skin_tone",3675},
	{"bicyclist_medium_skin_tone",3676},
	{"bicyclist_medium_dark_skin_tone",3677},
	{"bicyclist_dark_skin_tone",3678},
	{"woman-mountain-biking_light_skin_tone",3679},
	{"mountain_biking_woman_light_skin_tone",3680},
	{"woman-mountain-biking_medium_light_skin_tone",3681},
	{"mountain_biking_woman_medium_light_skin_tone",3682},
	{"woman-mountain-biking_medium_skin_tone",3683},
	{"mountain_biking_woman_medium_skin_tone",3684},
	{"woman-mountain-biking_medium_dark_skin_tone",3685},
	{"mountain_biking_woman_medium_dark_skin_tone",3686},
	{"woman-mountain-biking_dark_skin_tone",3687},
	{"mountain_biking_woman_dark_skin_tone",3688},
	{"man-mountain-biking_light_skin_tone",3689},
	{"mountain_biking_man_light_skin_tone",3690},
	{"man-mountain-biking_medium_light_skin_tone",3691},
	{"mountain_biking_man_medium_light_skin_tone",3692},
	{"man-mountain-biking_medium_skin_tone",3693},
	{"mountain_biking_man_medium_skin_tone",3694},
	{"man-mountain-biking_medium_dark_skin_tone",3695},
	{"mountain_biking_man_medium_dark_skin_tone",3696},
	{"man-mountain-biking_dark_skin_tone",3697},
	{"mountain_biking_man_dark_skin_tone",3698},
	{"mountain_bicyclist_light_skin_tone",3699},
	{"mountain_bicyclist_medium_light_skin_tone",3700},
	{"mountain_bicyclist_medium_skin_tone",3701},
	{"mountain_bicyclist_medium_dark_skin_tone",3702},
	{"mountain_bicyclist_dark_skin_tone",3703},
	{"woman-walking_light_skin_tone",3704},
	{"walking_woman_light_skin_tone",3705},
	{"woman-walking_medium_light_skin_tone",3706},
	{"walking_woman_medium_light_skin_tone",3707},
	{"woman-walking_medium_skin_tone",3708},
	{"walking_woman_medium_skin_tone",3709},
	{"woman-walking_medium_dark_skin_tone",3710},
	{"walking_woman_medium_dark_skin_tone",3711},
	{"woman-walking_dark_skin_tone",3712},
	{"walking_woman_dark_skin_tone",3713},
	{"man-walking_light_skin_tone",3714},
	{"walking_man_light_skin_tone",3715},
	{"man-walking_medium_light_skin_tone",3716},
	{"walking_man_medium_light_skin_tone",3717},
	{"man-walking_medium_skin_tone",3718},
	{"walking_man_medium_skin_tone",3719},
	{"man-walking_medium_dark_skin_tone",3720},
	{"walking_man_medium_dark_skin_tone",3721},
	{"man-walking_dark_skin_tone",3722},
	{"walking_man_dark_skin_tone",3723},
	{"walking_light_skin_tone",3724},
	{"walking_medium_light_skin_tone",3725},
	{"walking_medium_skin_tone",3726},
	{"walking_medium_dark_skin_tone",3727},
	{"walking_dark_skin_tone",3728},
	{"bath_light_skin_tone",3729},
	{"bath_medium_light_skin_tone",3730},
	{"bath_medium_skin_tone",3731},
	{"bath_medium_dark_skin_tone",3732},
	{"bath_dark_skin_tone",3733},
	{"sleeping_accommodation_light_skin_tone",3734},
	{"sleeping_accommodation_medium_light_skin_tone",3735},
	{"sleeping_accommodation_medium_skin_tone",3736},
	{"sleeping_accommodation_medium_dark_skin_tone",3737},
	{"sleeping_accommodation_dark_skin_tone",3738},
	{"pinched_fingers_light_skin_tone",3739},
	{"pinched_fingers_medium_light_skin_tone",3740},
	{"pinched_fingers_medium_skin_tone",3741},
	{"pinched_fingers_medium_dark_skin_tone",3742},
	{"pinched_fingers_dark_skin_tone",3743},
	{"pinching_hand_light_skin_tone",3744},
	{"pinching_hand_medium_light_skin_tone",3745},
	{"pinching_hand_medium_skin_tone",3746},
	{"pinching_hand_medium_dark_skin_tone",3747},
	{"pinching_hand_dark_skin_tone",3748},
	{"the_horns_light_skin_tone",3749},
	{"sign_of_the_horns_light_skin_tone",3750},
	{"metal_light_skin_tone",3751},
	{"the_horns_medium_light_skin_tone",3752},
	{"sign_of_the_horns_medium_light_skin_tone",3753},
	{"metal_medium_light_skin_tone",3754},
	{"the_horns_medium_skin_tone",3755},
	{"sign_of_the_horns_medium_skin_tone",3756},
	{"metal_medium_skin_tone",3757},
	{"the_horns_medium_dark_skin_tone",3758},
	{"sign_of_the_horns_medium_dark_skin_tone",3759},
	{"metal_medium_dark_skin_tone",3760},
	{"the_horns_dark_skin_tone",3761},
	{"sign_of_the_horns_dark_skin_tone",3762},
	{"metal_dark_skin_tone",3763},
	{"call_me_hand_light_skin_tone",3764},
	{"call_me_hand_medium_light_skin_tone",3765},
	{"call_me_hand_medium_skin_tone",3766},
	{"call_me_hand_medium_dark_skin_tone",3767},
	{"call_me_hand_dark_skin_tone",3768},
	{"raised_back_of_hand_light_skin_tone",3769},
	{"raised_back_of_hand_medium_light_skin_tone",3770},
	{"raised_back_of_hand_medium_skin_tone",3771},
	{"raised_back_of_hand_medium_dark_skin_tone",3772},
	{"raised_back_of_hand_dark_skin_tone",3773},
	{"left-facing_fist_light_skin_tone",3774},
	{"fist_left_light_skin_tone",3775},
	{"left-facing_fist_medium_light_skin_tone",3776},
	{"fist_left_medium_light_skin_tone",3777},
	{"left-facing_fist_medium_skin_tone",3778},
	{"fist_left_medium_skin_tone",3779},
	{"left-facing_fist_medium_dark_skin_tone",3780},
	{"fist_left_medium_dark_skin_tone",3781},
	{"left-facing_fist_dark_skin_tone",3782},
	{"fist_left_dark_skin_tone",3783},
	{"right-facing_fist_light_skin_tone",3784},
	{"fist_right_light_skin_tone",3785},
	{"right-facing_fist_medium_light_skin_tone",3786},
	{"fist_right_medium_light_skin_tone",3787},
	{"right-facing_fist_medium_skin_tone",3788},
	{"fist_right_medium_skin_tone",3789},
	{"right-facing_fist_medium_dark_skin_tone",3790},
	{"fist_right_medium_dark_skin_tone",3791},
	{"right-facing_fist_dark_skin_tone",3792},
	{"fist_right_dark_skin_tone",3793},
	{"crossed_fingers_light_skin_tone",3794},
	{"hand_with_index_and_middle_fingers_crossed_light_skin_tone",3795},
	{"crossed_fingers_medium_light_skin_tone",3796},
	{"hand_with_index_and_middle_fingers_crossed_medium_light_skin_tone",3797},
	{"crossed_fingers_medium_skin_tone",3798},
	{"hand_with_index_and_middle_fingers_crossed_medium_skin_tone",3799},
	{"crossed_fingers_medium_dark_skin_tone",3800},
	{"hand_with_index_and_middle_fingers_crossed_medium_dark_skin_tone",3801},
	{"crossed_fingers_dark_skin_tone",3802},
	{"hand_with_index_and_middle_fingers_crossed_dark_skin_tone",3803},
	{"i_love_you_hand_sign_light_skin_tone",3804},
	{"i_love_you_hand_sign_medium_light_skin_tone",3805},
	{"i_love_you_hand_sign_medium_skin_tone",3806},
	{"i_love_you_hand_sign_medium_dark_skin_tone",3807},
	{"i_love_you_hand_sign_dark_skin_tone",3808},
	{"woman-facepalming_light_skin_tone",3809},
	{"woman_facepalming_light_skin_tone",3810},
	{"woman-facepalming_medium_light_skin_tone",3811},
	{"woman_facepalming_medium_light_skin_tone",3812},
	{"woman-facepalming_medium_skin_tone",3813},
	{"woman_facepalming_medium_skin_tone",3814},
	{"woman-facepalming_medium_dark_skin_tone",3815},
	{"woman_facepalming_medium_dark_skin_tone",3816},
	{"woman-facepalming_dark_skin_tone",3817},
	{"woman_facepalming_dark_skin_tone",3818},
	{"man-facepalming_light_skin_tone",3819},
	{"man_facepalming_light_skin_tone",3820},
	{"man-facepalming_medium_light_skin_tone",3821},
	{"man_facepalming_medium_light_skin_tone",3822},
	{"man-facepalming_medium_skin_tone",3823},
	{"man_facepalming_medium_skin_tone",3824},
	{"man-facepalming_medium_dark_skin_tone",3825},
	{"man_facepalming_medium_dark_skin_tone",3826},
	{"man-facepalming_dark_skin_tone",3827},
	{"man_facepalming_dark_skin_tone",3828},
	{"face_palm_light_skin_tone",3829},
	{"face_palm_medium_light_skin_tone",3830},
	{"face_palm_medium_skin_tone",3831},
	{"face_palm_medium_dark_skin_tone",3832},
	{"face_palm_dark_skin_tone",3833},
	{"pregnant_woman_light_skin_tone",3834},
	{"pregnant_woman_medium_light_skin_tone",3835},
	{"pregnant_woman_medium_skin_tone",3836},
	{"pregnant_woman_medium_dark_skin_tone",3837},
	{"pregnant_woman_dark_skin_tone",3838},
	{"breast-feeding_light_skin_tone",3839},
	{"breast-feeding_medium_light_skin_tone",3840},
	{"breast-feeding_medium_skin_tone",3841},
	{"breast-feeding_medium_dark_skin_tone",3842},
	{"breast-feeding_dark_skin_tone",3843},
	{"palms_up_together_light_skin_tone",3844},
	{"palms_up_together_medium_light_skin_tone",3845},
	{"palms_up_together_medium_skin_tone",3846},
	{"palms_up_together_medium_dark_skin_tone",3847},
	{"palms_up_together_dark_skin_tone",3848},
	{"selfie_light_skin_tone",3849},
	{"selfie_medium_light_skin_tone",3850},
	{"selfie_medium_skin_tone",3851},
	{"selfie_medium_dark_skin_tone",3852},
	{"selfie_dark_skin_tone",3853},
	{"prince_light_skin_tone",3854},
	{"prince_medium_light_skin_tone",3855},
	{"prince_medium_skin_tone",3856},
	{"prince_medium_dark_skin_tone",3857},
	{"prince_dark_skin_tone",3858},
	{"woman_in_tuxedo_light_skin_tone",3859},
	{"woman_in_tuxedo_medium_light_skin_tone",3860},
	{"woman_in_tuxedo_medium_skin_tone",3861},
	{"woman_in_tuxedo_medium_dark_skin_tone",3862},
	{"woman_in_tuxedo_dark_skin_tone",3863},
	{"man_in_tuxedo_light_skin_tone",3864},
	{"man_in_tuxedo_medium_light_skin_tone",3865},
	{"man_in_tuxedo_medium_skin_tone",3866},
	{"man_in_tuxedo_medium_dark_skin_tone",3867},
	{"man_in_tuxedo_dark_skin_tone",3868},
	{"person_in_tuxedo_light_skin_tone",3869},
	{"person_in_tuxedo_medium_light_skin_tone",3870},
	{"person_in_tuxedo_medium_skin_tone",3871},
	{"person_in_tuxedo_medium_dark_skin_tone",3872},
	{"person_in_tuxedo_dark_skin_tone",3873},
	{"mrs_claus_light_skin_tone",3874},
	{"mother_christmas_light_skin_tone",3875},
	{"mrs_claus_medium_light_skin_tone",3876},
	{"mother_christmas_medium_light_skin_tone",3877},
	{"mrs_claus_medium_skin_tone",3878},
	{"mother_christmas_medium_skin_tone",3879},
	{"mrs_claus_medium_dark_skin_tone",3880},
	{"mother_christmas_medium_dark_skin_tone",3881},
	{"mrs_claus_dark_skin_tone",3882},
	{"mother_christmas_dark_skin_tone",3883},
	{"woman-shrugging_light_skin_tone",3884},
	{"woman_shrugging_light_skin_tone",3885},
	{"woman-shrugging_medium_light_skin_tone",3886},
	{"woman_shrugging_medium_light_skin_tone",3887},
	{"woman-shrugging_medium_skin_tone",3888},
	{"woman_shrugging_medium_skin_tone",3889},
	{"woman-shrugging_medium_dark_skin_tone",3890},
	{"woman_shrugging_medium_dark_skin_tone",3891},
	{"woman-shrugging_dark_skin_tone",3892},
	{"woman_shrugging_dark_skin_tone",3893},
	{"man-shrugging_light_skin_tone",3894},
	{"man_shrugging_light_skin_tone",3895},
	{"man-shrugging_medium_light_skin_tone",3896},
	{"man_shrugging_medium_light_skin_tone",3897},
	{"man-shrugging_medium_skin_tone",3898},
	{"man_shrugging_medium_skin_tone",3899},
	{"man-shrugging_medium_dark_skin_tone",3900},
	{"man_shrugging_medium_dark_skin_tone",3901},
	{"man-shrugging_dark_skin_tone",3902},
	{"man_shrugging_dark_skin_tone",3903},
	{"shrug_light_skin_tone",3904},
	{"shrug_medium_light_skin_tone",3905},
	{"shrug_medium_skin_tone",3906},
	{"shrug_medium_dark_skin_tone",3907},
	{"shrug_dark_skin_tone",3908},
	{"woman-cartwheeling_light_skin_tone",3909},
	{"woman_cartwheeling_light_skin_tone",3910},
	{"woman-cartwheeling_medium_light_skin_tone",3911},
	{"woman_cartwheeling_medium_light_skin_tone",3912},
	{"woman-cartwheeling_medium_skin_tone",3913},
	{"woman_cartwheeling_medium_skin_tone",3914},
	{"woman-cartwheeling_medium_dark_skin_tone",3915},
	{"woman_cartwheeling_medium_dark_skin_tone",3916},
	{"woman-cartwheeling_dark_skin_tone",3917},
	{"woman_cartwheeling_dark_skin_tone",3918},
	{"man-cartwheeling_light_skin_tone",3919},
	{"man_cartwheeling_light_skin_tone",3920},
	{"man-cartwheeling_medium_light_skin_tone",3921},
	{"man_cartwheeling_medium_light_skin_tone",3922},
	{"man-cartwheeling_medium_skin_tone",3923},
	{"man_cartwheeling_medium_skin_tone",3924},
	{"man-cartwheeling_medium_dark_skin_tone",3925},
	{"man_cartwheeling_medium_dark_skin_tone",3926},
	{"man-cartwheeling_dark_skin_tone",3927},
	{"man_cartwheeling_dark_skin_tone",3928},
	{"person_doing_cartwheel_light_skin_tone",3929},
	{"person_doing_cartwheel_medium_light_skin_tone",3930},
	{"person_doing_cartwheel_medium_skin_tone",3931},
	{"person_doing_cartwheel_medium_dark_skin_tone",3932},
	{"person_doing_cartwheel_dark_skin_tone",3933},
	{"woman-juggling_light_skin_tone",3934},
	{"woman_juggling_light_skin_tone",3935},
	{"woman-juggling_medium_light_skin_tone",3936},
	{"woman_juggling_medium_light_skin_tone",3937},
	{"woman-juggling_medium_skin_tone",3938},
	{"woman_juggling_medium_skin_tone",3939},
	{"woman-juggling_medium_dark_skin_tone",3940},
	{"woman_juggling_medium_dark_skin_tone",3941},
	{"woman-juggling_dark_skin_tone",3942},
	{"woman_juggling_dark_skin_tone",3943},
	{"man-juggling_light_skin_tone",3944},
	{"man_juggling_light_skin_tone",3945},
	{"man-juggling_medium_light_skin_tone",3946},
	{"man_juggling_medium_light_skin_tone",3947},
	{"man-juggling_medium_skin_tone",3948},
	{"man_juggling_medium_skin_tone",3949},
	{"man-juggling_medium_dark_skin_tone",3950},
	{"man_juggling_medium_dark_skin_tone",3951},
	{"man-juggling_dark_skin_tone",3952},
	{"man_juggling_dark_skin_tone",3953},
	{"juggling_light_skin_tone",3954},
	{"juggling_medium_light_skin_tone",3955},
	{"juggling_medium_skin_tone",3956},
	{"juggling_medium_dark_skin_tone",3957},
	{"juggling_dark_skin_tone",3958},
	{"woman-playing-water-polo_light_skin_tone",3959},
	{"woman_playing_water_polo_light_skin_tone",3960},
	{"woman-playing-water-polo_medium_light_skin_tone",3961},
	{"woman_playing_water_polo_medium_light_skin_tone",3962},
	{"woman-playing-water-polo_medium_skin_tone",3963},
	{"woman_playing_water_polo_medium_skin_tone",3964},
	{"woman-playing-water-polo_medium_dark_skin_tone",3965},
	{"woman_playing_water_polo_medium_dark_skin_tone",3966},
	{"woman-playing-water-polo_dark_skin_tone",3967},
	{"woman_playing_water_polo_dark_skin_tone",3968},
	{"man-playing-water-polo_light_skin_tone",3969},
	{"man_playing_water_polo_light_skin_tone",3970},
	{"man-playing-water-polo_medium_light_skin_tone",3971},
	{"man_playing_water_polo_medium_light_skin_tone",3972},
	{"man-playing-water-polo_medium_skin_tone",3973},
	{"man_playing_water_polo_medium_skin_tone",3974},
	{"man-playing-water-polo_medium_dark_skin_tone",3975},
	{"man_playing_water_polo_medium_dark_skin_tone",3976},
	{"man-playing-water-polo_dark_skin_tone",3977},
	{"man_playing_water_polo_dark_skin_tone",3978},
	{"water_polo_light_skin_tone",3979},
	{"water_polo_medium_light_skin_tone",3980},
	{"water_polo_medium_skin_tone",3981},
	{"water_polo_medium_dark_skin_tone",3982},
	{"water_polo_dark_skin_tone",3983},
	{"woman-playing-handball_light_skin_tone",3984},
	{"woman_playing_handball_light_skin_tone",3985},
	{"woman-playing-handball_medium_light_skin_tone",3986},
	{"woman_playing_handball_medium_light_skin_tone",3987},
	{"woman-playing-handball_medium_skin_tone",3988},
	{"woman_playing_handball_medium_skin_tone",3989},
	{"woman-playing-handball_medium_dark_skin_tone",3990},
	{"woman_playing_handball_medium_dark_skin_tone",3991},
	{"woman-playing-handball_dark_skin_tone",3992},
	{"woman_playing_handball_dark_skin_tone",3993},
	{"man-playing-handball_light_skin_tone",3994},
	{"man_playing_handball_light_skin_tone",3995},
	{"man-playing-handball_medium_light_skin_tone",3996},
	{"man_playing_handball_medium_light_skin_tone",3997},
	{"man-playing-handball_medium_skin_tone",3998},
	{"man_playing_handball_medium_skin_tone",3999},
	{"man-playing-handball_medium_dark_skin_tone",4000},
	{"man_playing_handball_medium_dark_skin_tone",4001},
	{"man-playing-handball_dark_skin_tone",4002},
	{"man_playing_handball_dark_skin_tone",4003},
	{"handball_light_skin_tone",4004},
	{"handball_medium_light_skin_tone",4005},
	{"handball_medium_skin_tone",4006},
	{"handball_medium_dark_skin_tone",4007},
	{"handball_dark_skin_tone",4008},
	{"ninja_light_skin_tone",4009},
	{"ninja_medium_light_skin_tone",4010},
	{"ninja_medium_skin_tone",4011},
	{"ninja_medium_dark_skin_tone",4012},
	{"ninja_dark_skin_tone",4013},
	{"leg_light_skin_tone",4014},
	{"leg_medium_light_skin_tone",4015},
	{"leg_medium_skin_tone",4016},
	{"leg_medium_dark_skin_tone",4017},
	{"leg_dark_skin_tone",4018},
	{"foot_light_skin_tone",4019},
	{"foot_medium_light_skin_tone",4020},
	{"foot_medium_skin_tone",4021},
	{"foot_medium_dark_skin_tone",4022},
	{"foot_dark_skin_tone",4023},
	{"female_superhero_light_skin_tone",4024},
	{"female_superhero_medium_light_skin_tone",4025},
	{"female_superhero_medium_skin_tone",4026},
	{"female_superhero_medium_dark_skin_tone",4027},
	{"female_superhero_dark_skin_tone",4028},
	{"male_superhero_light_skin_tone",4029},
	{"male_superhero_medium_light_skin_tone",4030},
	{"male_superhero_medium_skin_tone",4031},
	{"male_superhero_medium_dark_skin_tone",4032},
	{"male_superhero_dark_skin_tone",4033},
	{"superhero_light_skin_tone",4034},
	{"superhero_medium_light_skin_tone",4035},
	{"superhero_medium_skin_tone",4036},
	{"superhero_medium_dark_skin_tone",4037},
	{"superhero_dark_skin_tone",4038},
	{"female_supervillain_light_skin_tone",4039},
	{"female_supervillain_medium_light_skin_tone",4040},
	{"female_supervillain_medium_skin_tone",4041},
	{"female_supervillain_medium_dark_skin_tone",4042},
	{"female_supervillain_dark_skin_tone",4043},
	{"male_supervillain_light_skin_tone",4044},
	{"male_supervillain_medium_light_skin_tone",4045},
	{"male_supervillain_medium_skin_tone",4046},
	{"male_supervillain_medium_dark_skin_tone",4047},
	{"male_supervillain_dark_skin_tone",4048},
	{"supervillain_light_skin_tone",4049},
	{"supervillain_medium_light_skin_tone",4050},
	{"supervillain_medium_skin_tone",4051},
	{"supervillain_medium_dark_skin_tone",4052},
	{"supervillain_dark_skin_tone",4053},
	{"ear_with_hearing_aid_light_skin_tone",4054},
	{"ear_with_hearing_aid_medium_light_skin_tone",4055},
	{"ear_with_hearing_aid_medium_skin_tone",4056},
	{"ear_with_hearing_aid_medium_dark_skin_tone",4057},
	{"ear_with_hearing_aid_dark_skin_tone",4058},
	{"woman_standing_light_skin_tone",4059},
	{"woman_standing_medium_light_skin_tone",4060},
	{"woman_standing_medium_skin_tone",4061},
	{"woman_standing_medium_dark_skin_tone",4062},
	{"woman_standing_dark_skin_tone",4063},
	{"man_standing_light_skin_tone",4064},
	{"man_standing_medium_light_skin_tone",4065},
	{"man_standing_medium_skin_tone",4066},
	{"man_standing_medium_dark_skin_tone",4067},
	{"man_standing_dark_skin_tone",4068},
	{"standing_person_light_skin_tone",4069},
	{"standing_person_medium_light_skin_tone",4070},
	{"standing_person_medium_skin_tone",4071},
	{"standing_person_medium_dark_skin_tone",4072},
	{"standing_person_dark_skin_tone",4073},
	{"woman_kneeling_light_skin_tone",4074},
	{"woman_kneeling_medium_light_skin_tone",4075},
	{"woman_kneeling_medium_skin_tone",4076},
	{"woman_kneeling_medium_dark_skin_tone",4077},
	{"woman_kneeling_dark_skin_tone",4078},
	{"man_kneeling_light_skin_tone",4079},
	{"man_kneeling_medium_light_skin_tone",4080},
	{"man_kneeling_medium_skin_tone",4081},
	{"man_kneeling_medium_dark_skin_tone",4082},
	{"man_kneeling_dark_skin_tone",4083},
	{"kneeling_person_light_skin_tone",4084},
	{"kneeling_person_medium_light_skin_tone",4085},
	{"kneeling_person_medium_skin_tone",4086},
	{"kneeling_person_medium_dark_skin_tone",4087},
	{"kneeling_person_dark_skin_tone",4088},
	{"deaf_woman_light_skin_tone",4089},
	{"deaf_woman_medium_light_skin_tone",4090},
	{"deaf_woman_medium_skin_tone",4091},
	{"deaf_woman_medium_dark_skin_tone",4092},
	{"deaf_woman_dark_skin_tone",4093},
	{"deaf_man_light_skin_tone",4094},
	{"deaf_man_medium_light_skin_tone",4095},
	{"deaf_man_medium_skin_tone",4096},
	{"deaf_man_medium_dark_skin_tone",4097},
	{"deaf_man_dark_skin_tone",4098},
	{"deaf_person_light_skin_tone",4099},
	{"deaf_person_medium_light_skin_tone",4100},
	{"deaf_person_medium_skin_tone",4101},
	{"deaf_person_medium_dark_skin_tone",4102},
	{"deaf_person_dark_skin_tone",4103},
	{"farmer_light_skin_tone",4104},
	{"farmer_medium_light_skin_tone",4105},
	{"farmer_medium_skin_tone",4106},
	{"farmer_medium_dark_skin_tone",4107},
	{"farmer_dark_skin_tone",4108},
	{"cook_light_skin_tone",4109},
	{"cook_medium_light_skin_tone",4110},
	{"cook_medium_skin_tone",4111},
	{"cook_medium_dark_skin_tone",4112},
	{"cook_dark_skin_tone",4113},
	{"person_feeding_baby_light_skin_tone",4114},
	{"person_feeding_baby_medium_light_skin_tone",4115},
	{"person_feeding_baby_medium_skin_tone",4116},
	{"person_feeding_baby_medium_dark_skin_tone",4117},
	{"person_feeding_baby_dark_skin_tone",4118},
	{"mx_claus_light_skin_tone",4119},
	{"mx_claus_medium_light_skin_tone",4120},
	{"mx_claus_medium_skin_tone",4121},
	{"mx_claus_medium_dark_skin_tone",4122},
	{"mx_claus_dark_skin_tone",4123},
	{"student_light_skin_tone",4124},
	{"student_medium_light_skin_tone",4125},
	{"student_medium_skin_tone",4126},
	{"student_medium_dark_skin_tone",4127},
	{"student_dark_skin_tone",4128},
	{"singer_light_skin_tone",4129},
	{"singer_medium_light_skin_tone",4130},
	{"singer_medium_skin_tone",4131},
	{"singer_medium_dark_skin_tone",4132},
	{"singer_dark_skin_tone",4133},
	{"artist_light_skin_tone",4134},
	{"artist_medium_light_skin_tone",4135},
	{"artist_medium_skin_tone",4136},
	{"artist_medium_dark_skin_tone",4137},
	{"artist_dark_skin_tone",4138},
	{"teacher_light_skin_tone",4139},
	{"teacher_medium_light_skin_tone",4140},
	{"teacher_medium_skin_tone",4141},
	{"teacher_medium_dark_skin_tone",4142},
	{"teacher_dark_skin_tone",4143},
	{"factory_worker_light_skin_tone",4144},
	{"factory_worker_medium_light_skin_tone",4145},
	{"factory_worker_medium_skin_tone",4146},
	{"factory_worker_medium_dark_skin_tone",4147},
	{"factory_worker_dark_skin_tone",4148},
	{"technologist_light_skin_tone",4149},
	{"technologist_medium_light_skin_tone",4150},
	{"technologist_medium_skin_tone",4151},
	{"technologist_medium_dark_skin_tone",4152},
	{"technologist_dark_skin_tone",4153},
	{"office_worker_light_skin_tone",4154},
	{"office_worker_medium_light_skin_tone",4155},
	{"office_worker_medium_skin_tone",4156},
	{"office_worker_medium_dark_skin_tone",4157},
	{"office_worker_dark_skin_tone",4158},
	{"mechanic_light_skin_tone",4159},
	{"mechanic_medium_light_skin_tone",4160},
	{"mechanic_medium_skin_tone",4161},
	{"mechanic_medium_dark_skin_tone",4162},
	{"mechanic_dark_skin_tone",4163},
	{"scientist_light_skin_tone",4164},
	{"scientist_medium_light_skin_tone",4165},
	{"scientist_medium_skin_tone",4166},
	{"scientist_medium_dark_skin_tone",4167},
	{"scientist_dark_skin_tone",4168},
	{"astronaut_light_skin_tone",4169},
	{"astronaut_medium_light_skin_tone",4170},
	{"astronaut_medium_skin_tone",4171},
	{"astronaut_medium_dark_skin_tone",4172},
	{"astronaut_dark_skin_tone",4173},
	{"firefighter_light_skin_tone",4174},
	{"firefighter_medium_light_skin_tone",4175},
	{"firefighter_medium_skin_tone",4176},
	{"firefighter_medium_dark_skin_tone",4177},
	{"firefighter_dark_skin_tone",4178},
	{"people_holding_hands_light_skin_tone_light_skin_tone",4179},
	{"people_holding_hands_light_skin_tone_medium_light_skin_tone",4180},
	{"people_holding_hands_light_skin_tone_medium_skin_tone",4181},
	{"people_holding_hands_light_skin_tone_medium_dark_skin_tone",4182},
	{"people_holding_hands_light_skin_tone_dark_skin_tone",4183},
	{"people_holding_hands_medium_light_skin_tone_light_skin_tone",4184},
	{"people_holding_hands_medium_light_skin_tone_medium_light_skin_tone",4185},
	{"people_holding_hands_medium_light_skin_tone_medium_skin_tone",4186},
	{"people_holding_hands_medium_light_skin_tone_medium_dark_skin_tone",4187},
	{"people_holding_hands_medium_light_skin_tone_dark_skin_tone",4188},
	{"people_holding_hands_medium_skin_tone_light_skin_tone",4189},
	{"people_holding_hands_medium_skin_tone_medium_light_skin_tone",4190},
	{"people_holding_hands_medium_skin_tone_medium_skin_tone",4191},
	{"people_holding_hands_medium_skin_tone_medium_dark_skin_tone",4192},
	{"people_holding_hands_medium_skin_tone_dark_skin_tone",4193},
	{"people_holding_hands_medium_dark_skin_tone_light_skin_tone",4194},
	{"people_holding_hands_medium_dark_skin_tone_medium_light_skin_tone",4195},
	{"people_holding_hands_medium_dark_skin_tone_medium_skin_tone",4196},
	{"people_holding_hands_medium_dark_skin_tone_medium_dark_skin_tone",4197},
	{"people_holding_hands_medium_dark_skin_tone_dark_skin_tone",4198},
	{"people_holding_hands_dark_skin_tone_light_skin_tone",4199},
	{"people_holding_hands_dark_skin_tone_medium_light_skin_tone",4200},
	{"people_holding_hands_dark_skin_tone_medium_skin_tone",4201},
	{"people_holding_hands_dark_skin_tone_medium_dark_skin_tone",4202},
	{"people_holding_hands_dark_skin_tone_dark_skin_tone",4203},
	{"person_with_probing_cane_light_skin_tone",4204},
	{"person_with_probing_cane_medium_light_skin_tone",4205},
	{"person_with_probing_cane_medium_skin_tone",4206},
	{"person_with_probing_cane_medium_dark_skin_tone",4207},
	{"person_with_probing_cane_dark_skin_tone",4208},
	{"red_haired_person_light_skin_tone",4209},
	{"red_haired_person_medium_light_skin_tone",4210},
	{"red_haired_person_medium_skin_tone",4211},
	{"red_haired_person_medium_dark_skin_tone",4212},
	{"red_haired_person_dark_skin_tone",4213},
	{"curly_haired_person_light_skin_tone",4214},
	{"curly_haired_person_medium_light_skin_tone",4215},
	{"curly_haired_person_medium_skin_tone",4216},
	{"curly_haired_person_medium_dark_skin_tone",4217},
	{"curly_haired_person_dark_skin_tone",4218},
	{"bald_person_light_skin_tone",4219},
	{"bald_person_medium_light_skin_tone",4220},
	{"bald_person_medium_skin_tone",4221},
	{"bald_person_medium_dark_skin_tone",4222},
	{"bald_person_dark_skin_tone",4223},
	{"white_haired_person_light_skin_tone",4224},
	{"white_haired_person_medium_light_skin_tone",4225},
	{"white_haired_person_medium_skin_tone",4226},
	{"white_haired_person_medium_dark_skin_tone",4227},
	{"white_haired_person_dark_skin_tone",4228},
	{"person_in_motorized_wheelchair_light_skin_tone",4229},
	{"person_in_motorized_wheelchair_medium_light_skin_tone",4230},
	{"person_in_motorized_wheelchair_medium_skin_tone",4231},
	{"person_in_motorized_wheelchair_medium_dark_skin_tone",4232},
	{"person_in_motorized_wheelchair_dark_skin_tone",4233},
	{"person_in_manual_wheelchair_light_skin_tone",4234},
	{"person_in_manual_wheelchair_medium_light_skin_tone",4235},
	{"person_in_manual_wheelchair_medium_skin_tone",4236},
	{"person_in_manual_wheelchair_medium_dark_skin_tone",4237},
	{"person_in_manual_wheelchair_dark_skin_tone",4238},
	{"health_worker_light_skin_tone",4239},
	{"doctor_light_skin_tone",4240},
	{"health_worker_medium_light_skin_tone",4241},
	{"doctor_medium_light_skin_tone",4242},
	{"health_worker_medium_skin_tone",4243},
	{"doctor_medium_skin_tone",4244},
	{"health_worker_medium_dark_skin_tone",4245},
	{"doctor_medium_dark_skin_tone",4246},
	{"health_worker_dark_skin_tone",4247},
	{"doctor_dark_skin_tone",4248},
	{"judge_light_skin_tone",4249},
	{"judge_medium_light_skin_tone",4250},
	{"judge_medium_skin_tone",4251},
	{"judge_medium_dark_skin_tone",4252},
	{"judge_dark_skin_tone",4253},
	{"pilot_light_skin_tone",4254},
	{"pilot_medium_light_skin_tone",4255},
	{"pilot_medium_skin_tone",4256},
	{"pilot_medium_dark_skin_tone",4257},
	{"pilot_dark_skin_tone",4258},
	{"adult_light_skin_tone",4259},
	{"adult_medium_light_skin_tone",4260},
	{"adult_medium_skin_tone",4261},
	{"adult_medium_dark_skin_tone",4262},
	{"adult_dark_skin_tone",4263},
	{"child_light_skin_tone",4264},
	{"child_medium_light_skin_tone",4265},
	{"child_medium_skin_tone",4266},
	{"child_medium_dark_skin_tone",4267},
	{"child_dark_skin_tone",4268},
	{"older_adult_light_skin_tone",4269},
	{"older_adult_medium_light_skin_tone",4270},
	{"older_adult_medium_skin_tone",4271},
	{"older_adult_medium_dark_skin_tone",4272},
	{"older_adult_dark_skin_tone",4273},
	{"bearded_person_light_skin_tone",4274},
	{"bearded_person_medium_light_skin_tone",4275},
	{"bearded_person_medium_skin_tone",4276},
	{"bearded_person_medium_dark_skin_tone",4277},
	{"bearded_person_dark_skin_tone",4278},
	{"person_with_headscarf_light_skin_tone",4279},
	{"person_with_headscarf_medium_light_skin_tone",4280},
	{"person_with_headscarf_medium_skin_tone",4281},
	{"person_with_headscarf_medium_dark_skin_tone",4282},
	{"person_with_headscarf_dark_skin_tone",4283},
	{"woman_in_steamy_room_light_skin_tone",4284},
	{"woman_in_steamy_room_medium_light_skin_tone",4285},
	{"woman_in_steamy_room_medium_skin_tone",4286},
	{"woman_in_steamy_room_medium_dark_skin_tone",4287},
	{"woman_in_steamy_room_dark_skin_tone",4288},
	{"man_in_steamy_room_light_skin_tone",4289},
	{"man_in_steamy_room_medium_light_skin_tone",4290},
	{"man_in_steamy_room_medium_skin_tone",4291},
	{"man_in_steamy_room_medium_dark_skin_tone",4292},
	{"man_in_steamy_room_dark_skin_tone",4293},
	{"person_in_steamy_room_light_skin_tone",4294},
	{"person_in_steamy_room_medium_light_skin_tone",4295},
	{"person_in_steamy_room_medium_skin_tone",4296},
	{"person_in_steamy_room_medium_dark_skin_tone",4297},
	{"person_in_steamy_room_dark_skin_tone",4298},
	{"woman_climbing_light_skin_tone",4299},
	{"woman_climbing_medium_light_skin_tone",4300},
	{"woman_climbing_medium_skin_tone",4301},
	{"woman_climbing_medium_dark_skin_tone",4302},
	{"woman_climbing_dark_skin_tone",4303},
	{"man_climbing_light_skin_tone",4304},
	{"man_climbing_medium_light_skin_tone",4305},
	{"man_climbing_medium_skin_tone",4306},
	{"man_climbing_medium_dark_skin_tone",4307},
	{"man_climbing_dark_skin_tone",4308},
	{"person_climbing_light_skin_tone",4309},
	{"person_climbing_medium_light_skin_tone",4310},
	{"person_climbing_medium_skin_tone",4311},
	{"person_climbing_medium_dark_skin_tone",4312},
	{"person_climbing_dark_skin_tone",4313},
	{"woman_in_lotus_position_light_skin_tone",4314},
	{"woman_in_lotus_position_medium_light_skin_tone",4315},
	{"woman_in_lotus_position_medium_skin_tone",4316},
	{"woman_in_lotus_position_medium_dark_skin_tone",4317},
	{"woman_in_lotus_position_dark_skin_tone",4318},
	{"man_in_lotus_position_light_skin_tone",4319},
	{"man_in_lotus_position_medium_light_skin_tone",4320},
	{"man_in_lotus_position_medium_skin_tone",4321},
	{"man_in_lotus_position_medium_dark_skin_tone",4322},
	{"man_in_lotus_position_dark_skin_tone",4323},
	{"person_in_lotus_position_light_skin_tone",4324},
	{"person_in_lotus_position_medium_light_skin_tone",4325},
	{"person_in_lotus_position_medium_skin_tone",4326},
	{"person_in_lotus_position_medium_dark_skin_tone",4327},
	{"person_in_lotus_position_dark_skin_tone",4328},
	{"female_mage_light_skin_tone",4329},
	{"female_mage_medium_light_skin_tone",4330},
	{"female_mage_medium_skin_tone",4331},
	{"female_mage_medium_dark_skin_tone",4332},
	{"female_mage_dark_skin_tone",4333},
	{"male_mage_light_skin_tone",4334},
	{"male_mage_medium_light_skin_tone",4335},
	{"male_mage_medium_skin_tone",4336},
	{"male_mage_medium_dark_skin_tone",4337},
	{"male_mage_dark_skin_tone",4338},
	{"mage_light_skin_tone",4339},
	{"mage_medium_light_skin_tone",4340},
	{"mage_medium_skin_tone",4341},
	{"mage_medium_dark_skin_tone",4342},
	{"mage_dark_skin_tone",4343},
	{"female_fairy_light_skin_tone",4344},
	{"female_fairy_medium_light_skin_tone",4345},
	{"female_fairy_medium_skin_tone",4346},
	{"female_fairy_medium_dark_skin_tone",4347},
	{"female_fairy_dark_skin_tone",4348},
	{"male_fairy_light_skin_tone",4349},
	{"male_fairy_medium_light_skin_tone",4350},
	{"male_fairy_medium_skin_tone",4351},
	{"male_fairy_medium_dark_skin_tone",4352},
	{"male_fairy_dark_skin_tone",4353},
	{"fairy_light_skin_tone",4354},
	{"fairy_medium_light_skin_tone",4355},
	{"fairy_medium_skin_tone",4356},
	{"fairy_medium_dark_skin_tone",4357},
	{"fairy_dark_skin_tone",4358},
	{"female_vampire_light_skin_tone",4359},
	{"female_vampire_medium_light_skin_tone",4360},
	{"female_vampire_medium_skin_tone",4361},
	{"female_vampire_medium_dark_skin_tone",4362},
	{"female_vampire_dark_skin_tone",4363},
	{"male_vampire_light_skin_tone",4364},
	{"male_vampire_medium_light_skin_tone",4365},
	{"male_vampire_medium_skin_tone",4366},
	{"male_vampire_medium_dark_skin_tone",4367},
	{"male_vampire_dark_skin_tone",4368},
	{"vampire_light_skin_tone",4369},
	{"vampire_medium_light_skin_tone",4370},
	{"vampire_medium_skin_tone",4371},
	{"vampire_medium_dark_skin_tone",4372},
	{"vampire_dark_skin_tone",4373},
	{"mermaid_light_skin_tone",4374},
	{"mermaid_medium_light_skin_tone",4375},
	{"mermaid_medium_skin_tone",4376},
	{"mermaid_medium_dark_skin_tone",4377},
	{"mermaid_dark_skin_tone",4378},
	{"merman_light_skin_tone",4379},
	{"merman_medium_light_skin_tone",4380},
	{"merman_medium_skin_tone",4381},
	{"merman_medium_dark_skin_tone",4382},
	{"merman_dark_skin_tone",4383},
	{"merperson_light_skin_tone",4384},
	{"merperson_medium_light_skin_tone",4385},
	{"merperson_medium_skin_tone",4386},
	{"merperson_medium_dark_skin_tone",4387},
	{"merperson_dark_skin_tone",4388},
	{"female_elf_light_skin_tone",4389},
	{"female_elf_medium_light_skin_tone",4390},
	{"female_elf_medium_skin_tone",4391},
	{"female_elf_medium_dark_skin_tone",4392},
	{"female_elf_dark_skin_tone",4393},
	{"male_elf_light_skin_tone",4394},
	{"male_elf_medium_light_skin_tone",4395},
	{"male_elf_medium_skin_tone",4396},
	{"male_elf_medium_dark_skin_tone",4397},
	{"male_elf_dark_skin_tone",4398},
	{"elf_light_skin_tone",4399},
	{"elf_medium_light_skin_tone",4400},
	{"elf_medium_skin_tone",4401},
	{"elf_medium_dark_skin_tone",4402},
	{"elf_dark_skin_tone",4403},
	{"point_up_light_skin_tone",4404},
	{"point_up_medium_light_skin_tone",4405},
	{"point_up_medium_skin_tone",4406},
	{"point_up_medium_dark_skin_tone",4407},
	{"point_up_dark_skin_tone",4408},
	{"woman-bouncing-ball_light_skin_tone",4409},
	{"basketball_woman_light_skin_tone",4410},
	{"woman-bouncing-ball_medium_light_skin_tone",4411},
	{"basketball_woman_medium_light_skin_tone",4412},
	{"woman-bouncing-ball_medium_skin_tone",4413},
	{"basketball_woman_medium_skin_tone",4414},
	{"woman-bouncing-ball_medium_dark_skin_tone",4415},
	{"basketball_woman_medium_dark_skin_tone",4416},
	{"woman-bouncing-ball_dark_skin_tone",4417},
	{"basketball_woman_dark_skin_tone",4418},
	{"man-bouncing-ball_light_skin_tone",4419},
	{"basketball_man_light_skin_tone",4420},
	{"man-bouncing-ball_medium_light_skin_tone",4421},
	{"basketball_man_medium_light_skin_tone",4422},
	{"man-bouncing-ball_medium_skin_tone",4423},
	{"basketball_man_medium_skin_tone",4424},
	{"man-bouncing-ball_medium_dark_skin_tone",4425},
	{"basketball_man_medium_dark_skin_tone",4426},
	{"man-bouncing-ball_dark_skin_tone",4427},
	{"basketball_man_dark_skin_tone",4428},
	{"person_with_ball_light_skin_tone",4429},
	{"person_with_ball_medium_light_skin_tone",4430},
	{"person_with_ball_medium_skin_tone",4431},
	{"person_with_ball_medium_dark_skin_tone",4432},
	{"person_with_ball_dark_skin_tone",4433},
	{"fist_light_skin_tone",4434},
	{"fist_raised_light_skin_tone",4435},
	{"fist_medium_light_skin_tone",4436},
	{"fist_raised_medium_light_skin_tone",4437},
	{"fist_medium_skin_tone",4438},
	{"fist_raised_medium_skin_tone",4439},
	{"fist_medium_dark_skin_tone",4440},
	{"fist_raised_medium_dark_skin_tone",4441},
	{"fist_dark_skin_tone",4442},
	{"fist_raised_dark_skin_tone",4443},
	{"hand_light_skin_tone",4444},
	{"raised_hand_light_skin_tone",4445},
	{"hand_medium_light_skin_tone",4446},
	{"raised_hand_medium_light_skin_tone",4447},
	{"hand_medium_skin_tone",4448},
	{"raised_hand_medium_skin_tone",4449},
	{"hand_medium_dark_skin_tone",4450},
	{"raised_hand_medium_dark_skin_tone",4451},
	{"hand_dark_skin_tone",4452},
	{"raised_hand_dark_skin_tone",4453},
	{"v_light_skin_tone",4454},
	{"v_medium_light_skin_tone",4455},
	{"v_medium_skin_tone",4456},
	{"v_medium_dark_skin_tone",4457},
	{"v_dark_skin_tone",4458},
	{"writing_hand_light_skin_tone",4459},
	{"writing_hand_medium_light_skin_tone",4460},
	{"writing_hand_medium_skin_tone",4461},
	{"writing_hand_medium_dark_skin_tone",4462},
	{"writing_hand_dark_skin_tone",4463},
	{"mattermost",4464},
};

const QString& EmojiMap::idToString (uint32_t id)
{
	return emojiStrings[id];
}

const QString& EmojiMap::nameToString (const QString& name)
{
	int id = emojiMap.value (name);
	return idToString (id);
}

uint32_t EmojiMap::nameToId (const QString& emojiName)
{
	return emojiMap.value (emojiName);
}

} /* namespace Mattermost */

