/*
 * Case Study: TDF#98856
 * Root Cause: Premature deletion of empty text frame during MouseButtonDown event.
 * Fix: Override deletion behavior by toggling the bDontDeleteReally flag.
 */

// File: sd/source/ui/func/futext.cxx

// --- VULNERABLE CODE ---
if( mpView->IsTextEdit() )
{
    mpView->SdrEndTextEdit(); // BUG: Deletes frame if empty
    bJustEndedEdit = true;
    ...
}

// --- SECURE CODE (THE FIX) ---
if( mpView->IsTextEdit() )
{
    // Pass bDontDeleteReally=true to maintain state for subsequent BegDragObj
    mpView->SdrEndTextEdit(/*bDontDeleteReally=*/true);
    bJustEndedEdit = true;
    ...
}
