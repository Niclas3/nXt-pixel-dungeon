#ifndef NTASSETS_H
#define NTASSETS_H

#include <raylib.h>

typedef struct {
    char *EFFECTS;
    char *FIREBALL;
    char *SPECKS;
    char *SPELL_ICONS;
} NTEffects;

typedef struct {
    char *TERRAIN_FEATURES;
    char *VISUAL_GRID;
    char *WALL_BLOCKING;
    char *TILES_SEWERS;
    char *TILES_PRISON;
    char *TILES_CAVES;
    char *TILES_CITY;
    char *TILES_HALLS;
    char *WATER_SEWERS;
    char *WATER_PRISON;
    char *WATER_CAVES;
    char *WATER_CITY;
    char *WATER_HALLS;
    char *WEAK_FLOOR;
    char *SEWER_BOSS;
    char *PRISON_QUEST;
    char *PRISON_EXIT;
    char *CAVES_BOSS;
    char *CITY_BOSS;
    char *HALLS_SP;
} NTEnvironment;

// TODO include other font assets here? Some are platform specific though...
// public

typedef struct {
    char *PIXELFONT;
} NTFonts;


typedef struct {
    char *ARCS_BG;
    char *ARCS_FG;

    char *BANNERS;
    char *BADGES;
    char *LOCKED;

    char *CHROME;
    char *ICONS;
    char *STATUS;
    char *MENU;
    char *MENU_BTN;
    char *TOOLBAR;
    char *SHADOW;
    char *BOSSHP;

    char *SURFACE;

    char *LOADING_SEWERS;
    char *LOADING_PRISON;
    char *LOADING_CAVES;
    char *LOADING_CITY;
    char *LOADING_HALLS;

    char *BUFFS_SMALL;
    char *BUFFS_LARGE;

    char *TALENT_ICONS;
    char *TALENT_BUTTON;

    char *HERO_ICONS;

    char *RADIAL_MENU;
} NTInterfaces;

typedef struct {
    char *THEME_1;
    char *THEME_2;
    char *SEWERS_1;
    char *SEWERS_2;
    char *SEWERS_BOSS;
    char *PRISON_1;
    char *PRISON_2;
    char *PRISON_BOSS;
    char *CAVES_1;
    char *CAVES_2;
    char *CAVES_BOSS;
    char *CITY_1;
    char *CITY_2;
    char *CITY_BOSS;
    char *HALLS_1;
    char *HALLS_2;
    char *HALLS_BOSS;
} NTMusic;

NTEffects asset_effects = {
    .EFFECTS = "effects/effects.png",
    .FIREBALL = "effects/fireball.png",
    .SPECKS = "effects/specks.png",
    .SPELL_ICONS = "effects/spell_icons.png",
};

NTEnvironment asset_environment = {
    .TERRAIN_FEATURES = "environment/terrain_features.png",
    .VISUAL_GRID = "environment/visual_grid.png",
    .WALL_BLOCKING = "environment/wall_blocking.png",
    .TILES_SEWERS = "environment/tiles_sewers.png",
    .TILES_PRISON = "environment/tiles_prison.png",
    .TILES_CAVES = "environment/tiles_caves.png",
    .TILES_CITY = "environment/tiles_city.png",
    .TILES_HALLS = "environment/tiles_halls.png",
    .WATER_SEWERS = "environment/water0.png",
    .WATER_PRISON = "environment/water1.png",
    .WATER_CAVES = "environment/water2.png",
    .WATER_CITY = "environment/water3.png",
    .WATER_HALLS = "environment/water4.png",
    .WEAK_FLOOR = "environment/custom_tiles/weak_floor.png",
    .SEWER_BOSS = "environment/custom_tiles/sewer_boss.png",
    .PRISON_QUEST = "environment/custom_tiles/prison_quests.png",
    .PRISON_EXIT = "environment/custom_tiles/prison_exit.png",
    .CAVES_BOSS = "environment/custom_tiles/caves_boss.png",
    .CITY_BOSS = "environment/custom_tiles/city_boss.png",
    .HALLS_SP = "environment/custom_tiles/halls_special.png",
};
NTFonts asset_fonts = {.PIXELFONT = "fonts/pixel_font.png"};
NTInterfaces asset_interfaces = {
    .ARCS_BG = "interfaces/arcs1.png",
    .ARCS_FG = "interfaces/arcs2.png",
    .BANNERS = "interfaces/banners.png",
    .BADGES = "interfaces/badges.png",
    .LOCKED = "interfaces/locked_badge.png",
    .CHROME = "interfaces/chrome.png",
    .ICONS = "interfaces/icons.png",
    .STATUS = "interfaces/status_pane.png",
    .MENU = "interfaces/menu_pane.png",
    .MENU_BTN = "interfaces/menu_button.png",
    .TOOLBAR = "interfaces/toolbar.png",
    .SHADOW = "interfaces/shadow.png",
    .BOSSHP = "interfaces/boss_hp.png",
    .SURFACE = "interfaces/surface.png",
    .LOADING_SEWERS = "interfaces/loading_sewers.png",
    .LOADING_PRISON = "interfaces/loading_prison.png",
    .LOADING_CAVES = "interfaces/loading_caves.png",
    .LOADING_CITY = "interfaces/loading_city.png",
    .LOADING_HALLS = "interfaces/loading_halls.png",
    .BUFFS_SMALL = "interfaces/buffs.png",
    .BUFFS_LARGE = "interfaces/large_buffs.png",
    .TALENT_ICONS = "interfaces/talent_icons.png",
    .TALENT_BUTTON = "interfaces/talent_button.png",
    .HERO_ICONS = "interfaces/hero_icons.png",
    .RADIAL_MENU = "interfaces/radial_menu.png"
};

//
// // these points to resource bundles, not raw asset files
// public static class Messages
// {
// public
//     static final String ACTORS = "messages/actors/actors";
// public
//     static final String ITEMS = "messages/items/items";
// public
//     static final String JOURNAL = "messages/journal/journal";
// public
//     static final String LEVELS = "messages/levels/levels";
// public
//     static final String MISC = "messages/misc/misc";
// public
//     static final String PLANTS = "messages/plants/plants";
// public
//     static final String SCENES = "messages/scenes/scenes";
// public
//     static final String UI = "messages/ui/ui";
// public
//     static final String WINDOWS = "messages/windows/windows";
// }
//


NTMusic asset_music = {.THEME_1 = "music/theme_1.ogg",
                       .THEME_2 = "music/theme_2.ogg",
                       .SEWERS_1 = "music/sewers_1.ogg",
                       .SEWERS_2 = "music/sewers_2.ogg",
                       .SEWERS_BOSS = "music/sewers_boss.ogg",
                       .PRISON_1 = "music/prison_1.ogg",
                       .PRISON_2 = "music/prison_2.ogg",
                       .PRISON_BOSS = "music/prison_boss.ogg",
                       .CAVES_1 = "music/caves_1.ogg",
                       .CAVES_2 = "music/caves_2.ogg",
                       .CAVES_BOSS = "music/caves_boss.ogg",
                       .CITY_1 = "music/city_1.ogg",
                       .CITY_2 = "music/city_2.ogg",
                       .CITY_BOSS = "music/city_boss.ogg",
                       .HALLS_1 = "music/halls_1.ogg",
                       .HALLS_2 = "music/halls_2.ogg",
                       .HALLS_BOSS = "music/halls_boss.ogg"
};

char* NTGetAssertPath(char* symbol){
    return TextFormat("romfs:/assets/%s",symbol);
}

// public static class Sounds
// {
// public
//     static final String CLICK = "sounds/click.mp3";
// public
//     static final String BADGE = "sounds/badge.mp3";
// public
//     static final String GOLD = "sounds/gold.mp3";
//
// public
//     static final String OPEN = "sounds/door_open.mp3";
// public
//     static final String UNLOCK = "sounds/unlock.mp3";
// public
//     static final String ITEM = "sounds/item.mp3";
// public
//     static final String DEWDROP = "sounds/dewdrop.mp3";
// public
//     static final String STEP = "sounds/step.mp3";
// public
//     static final String WATER = "sounds/water.mp3";
// public
//     static final String GRASS = "sounds/grass.mp3";
// public
//     static final String TRAMPLE = "sounds/trample.mp3";
// public
//     static final String STURDY = "sounds/sturdy.mp3";
//
// public
//     static final String HIT = "sounds/hit.mp3";
// public
//     static final String MISS = "sounds/miss.mp3";
// public
//     static final String HIT_SLASH = "sounds/hit_slash.mp3";
// public
//     static final String HIT_STAB = "sounds/hit_stab.mp3";
// public
//     static final String HIT_CRUSH = "sounds/hit_crush.mp3";
// public
//     static final String HIT_MAGIC = "sounds/hit_magic.mp3";
// public
//     static final String HIT_STRONG = "sounds/hit_strong.mp3";
// public
//     static final String HIT_PARRY = "sounds/hit_parry.mp3";
// public
//     static final String HIT_ARROW = "sounds/hit_arrow.mp3";
// public
//     static final String ATK_SPIRITBOW = "sounds/atk_spiritbow.mp3";
// public
//     static final String ATK_CROSSBOW = "sounds/atk_crossbow.mp3";
// public
//     static final String HEALTH_WARN = "sounds/health_warn.mp3";
// public
//     static final String HEALTH_CRITICAL = "sounds/health_critical.mp3";
//
// public
//     static final String DESCEND = "sounds/descend.mp3";
// public
//     static final String EAT = "sounds/eat.mp3";
// public
//     static final String READ = "sounds/read.mp3";
// public
//     static final String LULLABY = "sounds/lullaby.mp3";
// public
//     static final String DRINK = "sounds/drink.mp3";
// public
//     static final String SHATTER = "sounds/shatter.mp3";
// public
//     static final String ZAP = "sounds/zap.mp3";
// public
//     static final String LIGHTNING = "sounds/lightning.mp3";
// public
//     static final String LEVELUP = "sounds/levelup.mp3";
// public
//     static final String DEATH = "sounds/death.mp3";
// public
//     static final String CHALLENGE = "sounds/challenge.mp3";
// public
//     static final String CURSED = "sounds/cursed.mp3";
// public
//     static final String TRAP = "sounds/trap.mp3";
// public
//     static final String EVOKE = "sounds/evoke.mp3";
// public
//     static final String TOMB = "sounds/tomb.mp3";
// public
//     static final String ALERT = "sounds/alert.mp3";
// public
//     static final String MELD = "sounds/meld.mp3";
// public
//     static final String BOSS = "sounds/boss.mp3";
// public
//     static final String BLAST = "sounds/blast.mp3";
// public
//     static final String PLANT = "sounds/plant.mp3";
// public
//     static final String RAY = "sounds/ray.mp3";
// public
//     static final String BEACON = "sounds/beacon.mp3";
// public
//     static final String TELEPORT = "sounds/teleport.mp3";
// public
//     static final String CHARMS = "sounds/charms.mp3";
// public
//     static final String MASTERY = "sounds/mastery.mp3";
// public
//     static final String PUFF = "sounds/puff.mp3";
// public
//     static final String ROCKS = "sounds/rocks.mp3";
// public
//     static final String BURNING = "sounds/burning.mp3";
// public
//     static final String FALLING = "sounds/falling.mp3";
// public
//     static final String GHOST = "sounds/ghost.mp3";
// public
//     static final String SECRET = "sounds/secret.mp3";
// public
//     static final String BONES = "sounds/bones.mp3";
// public
//     static final String BEE = "sounds/bee.mp3";
// public
//     static final String DEGRADE = "sounds/degrade.mp3";
// public
//     static final String MIMIC = "sounds/mimic.mp3";
// public
//     static final String DEBUFF = "sounds/debuff.mp3";
// public
//     static final String CHARGEUP = "sounds/chargeup.mp3";
// public
//     static final String GAS = "sounds/gas.mp3";
// public
//     static final String CHAINS = "sounds/chains.mp3";
// public
//     static final String SCAN = "sounds/scan.mp3";
// public
//     static final String SHEEP = "sounds/sheep.mp3";
//
// }

//
// public static class Splashes
// {
// public
//     static final String WARRIOR = "splashes/warrior.jpg";
// public
//     static final String MAGE = "splashes/mage.jpg";
// public
//     static final String ROGUE = "splashes/rogue.jpg";
// public
//     static final String HUNTRESS = "splashes/huntress.jpg";
// }
//
// public static class Sprites
// {
// public
//     static final String ITEMS = "sprites/items.png";
// public
//     static final String ITEM_ICONS = "sprites/item_icons.png";
//
// public
//     static final String WARRIOR = "sprites/warrior.png";
// public
//     static final String MAGE = "sprites/mage.png";
// public
//     static final String ROGUE = "sprites/rogue.png";
// public
//     static final String HUNTRESS = "sprites/huntress.png";
// public
//     static final String AVATARS = "sprites/avatars.png";
// public
//     static final String PET = "sprites/pet.png";
// public
//     static final String AMULET = "sprites/amulet.png";
//
// public
//     static final String RAT = "sprites/rat.png";
// public
//     static final String BRUTE = "sprites/brute.png";
// public
//     static final String SPINNER = "sprites/spinner.png";
// public
//     static final String DM300 = "sprites/dm300.png";
// public
//     static final String WRAITH = "sprites/wraith.png";
// public
//     static final String UNDEAD = "sprites/undead.png";
// public
//     static final String KING = "sprites/king.png";
// public
//     static final String PIRANHA = "sprites/piranha.png";
// public
//     static final String EYE = "sprites/eye.png";
// public
//     static final String GNOLL = "sprites/gnoll.png";
// public
//     static final String CRAB = "sprites/crab.png";
// public
//     static final String GOO = "sprites/goo.png";
// public
//     static final String SWARM = "sprites/swarm.png";
// public
//     static final String SKELETON = "sprites/skeleton.png";
// public
//     static final String SHAMAN = "sprites/shaman.png";
// public
//     static final String THIEF = "sprites/thief.png";
// public
//     static final String TENGU = "sprites/tengu.png";
// public
//     static final String SHEEP = "sprites/sheep.png";
// public
//     static final String KEEPER = "sprites/shopkeeper.png";
// public
//     static final String BAT = "sprites/bat.png";
// public
//     static final String ELEMENTAL = "sprites/elemental.png";
// public
//     static final String MONK = "sprites/monk.png";
// public
//     static final String WARLOCK = "sprites/warlock.png";
// public
//     static final String GOLEM = "sprites/golem.png";
// public
//     static final String STATUE = "sprites/statue.png";
// public
//     static final String SUCCUBUS = "sprites/succubus.png";
// public
//     static final String SCORPIO = "sprites/scorpio.png";
// public
//     static final String FISTS = "sprites/yog_fists.png";
// public
//     static final String YOG = "sprites/yog.png";
// public
//     static final String LARVA = "sprites/larva.png";
// public
//     static final String GHOST = "sprites/ghost.png";
// public
//     static final String MAKER = "sprites/wandmaker.png";
// public
//     static final String TROLL = "sprites/blacksmith.png";
// public
//     static final String IMP = "sprites/demon.png";
// public
//     static final String RATKING = "sprites/ratking.png";
// public
//     static final String BEE = "sprites/bee.png";
// public
//     static final String MIMIC = "sprites/mimic.png";
// public
//     static final String ROT_LASH = "sprites/rot_lasher.png";
// public
//     static final String ROT_HEART = "sprites/rot_heart.png";
// public
//     static final String GUARD = "sprites/guard.png";
// public
//     static final String WARDS = "sprites/wards.png";
// public
//     static final String GUARDIAN = "sprites/guardian.png";
// public
//     static final String SLIME = "sprites/slime.png";
// public
//     static final String SNAKE = "sprites/snake.png";
// public
//     static final String NECRO = "sprites/necromancer.png";
// public
//     static final String GHOUL = "sprites/ghoul.png";
// public
//     static final String RIPPER = "sprites/ripper.png";
// public
//     static final String SPAWNER = "sprites/spawner.png";
// public
//     static final String DM100 = "sprites/dm100.png";
// public
//     static final String PYLON = "sprites/pylon.png";
// public
//     static final String DM200 = "sprites/dm200.png";
// public
//     static final String LOTUS = "sprites/lotus.png";
// public
//     static final String NINJA_LOG = "sprites/ninja_log.png";
// public
//     static final String SPIRIT_HAWK = "sprites/spirit_hawk.png";
// public
//     static final String RED_SENTRY = "sprites/red_sentry.png";
// }
// }
#endif
