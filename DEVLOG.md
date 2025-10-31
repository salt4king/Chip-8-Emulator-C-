## 🗓️ 2025-10-30
### 🧩 Goal
Implement ROM loading and initialize memory/registers.

### ✅ Progress
- Added `loadROM()` function that loads binary data from `.ch8` files.
- ROMs now load starting at memory address `0x200`.
- Confirmed memory writing works for test ROMs.

### ⚠️ Notes
- Added `<vector>` for dynamic buffer handling.
- Using `using namespace std;` for now to simplify syntax.
- Next step: start building the **fetch–decode–execute** loop.
