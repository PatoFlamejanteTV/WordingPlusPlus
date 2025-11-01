# Bug Report: Out-of-Bounds Array Access in `CWordPadApp::PrintTwips`

## 1. Location

*   **File:** `wordpad.cpp`
*   **Function:** `CWordPadApp::PrintTwips`
*   **Line:** 628

## 2. Bug Description

The `PrintTwips` function, responsible for converting twips to a string representation based on the current measurement unit, contains a critical out-of-bounds array access. This bug can lead to application instability, crashes, or other undefined behavior when printing or displaying measurements.

*   **Expected Behavior:** The function should access the `m_units` array using an index corresponding to the currently selected measurement unit to determine if a space should be inserted before the unit's abbreviation.
*   **Actual Behavior:** The code incorrectly uses `m_nUnits` as the array index. Since `m_nUnits` is a constant with a value of 7, and the `m_units` array is declared with a size of 7 (valid indices are 0-6), this results in reading memory just beyond the end of the array.

## 3. Root Cause Analysis

The root cause of the bug is an off-by-one error in array indexing. The constant `m_nNumUnits` is defined as 7, which represents the total count of measurement units. However, this value is mistakenly used as an index for the `m_units` array. The correct approach is to use the index of the *currently selected* unit. The application provides a `GetUnits()` method to retrieve this index.

The problematic line of code is:
```cpp
if (m_units[m_nUnits].m_bSpaceAbbrev)
```

## 4. Proposed Fix Strategy

The fix is to replace the incorrect index `m_nUnits` with the return value of the `GetUnits()` method, which provides the correct index for the active unit.

*   **Change:** Modify line 628 in `wordpad.cpp`.
*   **From:** `if (m_units[m_nUnits].m_bSpaceAbbrev)`
*   **To:** `if (m_units[GetUnits()].m_bSpaceAbbrev)`

This change is minimal, targeted, and directly resolves the out-of-bounds access. It ensures that the function's behavior aligns with the user's selected measurement unit, preventing potential memory corruption and application crashes.
